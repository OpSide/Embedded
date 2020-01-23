/////////////////////////////////////
//		Copyrights (C) to	   /////
//		   January 2020		  /////
//*/ Raviv Nachum ID 311453096  //
//*/ Barak Pahima ID 203484217 //
////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "doubly_list_users.h"
#include "doubly_list_tickets.h"
#include "print_l.h"
//#include "doublyLinkedList.h"

char* fp_path;

#define USERS_PATH "users.txt"
/***
* This is the path where the users are located.
***/

#define TICKETS_PATH "tickets.txt"
/***
* This is the path where the item file is located.
***/

#define LOG_PATH "log.txt"
/***
* This is the path where the log file is located.
* Open this file and append new records into it.
***/

void ReadUsers(char* path, listUsers* lst);
void DeleteUser(char* path, listUsers* lst);
void AddUser(char* path, listUsers* lst);

void sortList(nodeTickets* head);
void ReadTickets(char* path, listTicket* lst);
void DeleteTicket(char* path, listTicket* lst);
void AddTickets(char* path, listTicket* lst);
void UpdateTicket(listTicket* lst);
void SearchByTwoFields(listTicket* lst);
void SearchByModel(listTicket* lst);
void SearchByColor(listTicket* lst);
void SearchByPrice(listTicket* lst);
void SearchByStatus(listTicket* lst);
void SearchByDate(listTicket* lst);
void getDateTime(int* day, int* month, int* year, int* hours, int* mins);

void menu(user* current, listUsers* tickets);

/***
* Handle function: get's the path of the users file, and print all users information.
* You may change it according to your needs.
***/

void RedColor () {
  printf("\033[1;31m");
}
void WhiteColor () {
  printf("\033[0m");
}
void GreenColor () {
  printf("\033[1;32m");
}
void LightBlue () {
  printf("\033[1;36m");
}
//This function hangle with logs implementation. getting 2 objects: char that describe the operation and audit the current user
void Logs (user* current, char operation [15])
{
		FILE* fp;
		int day, month, year, hours, mins;
		getDateTime (&day, &month, &year, &hours, &mins);
		fopen_s(&fp, LOG_PATH, "a");
		// Username ^^ Operation ^^ Date ^^ Time
		fprintf_s(fp, "%-15s %-15s %02d/%02d/%d %02d:%02d\n", current->userName, operation, day, month, year, hours, mins);
		fclose(fp);
}
void Delay(int number_of_seconds)
{
	// Converting time into milli_seconds 
	int milli_seconds = 1000 * number_of_seconds;

	// Storing start time 
	clock_t start_time = clock();

	// looping till required time is not achieved 
	while (clock() < start_time + milli_seconds);
}

/***
* Handle function: Returns by referfance the current date and time
***/
void removeSpaces(char* str)
{
	// To keep track of non-space character count 
	int count = 0;

	// Traverse the given string. If current character 
	// is not space, then place it at index 'count++' 
	for (int i = 0; str[i]; i++)
		if (str[i] != ' ')
			str[count++] = str[i]; // here count is 
								   // incremented 
	str[count] = '\0';
}

void main() {

	int day, month, year, hours, mins;
	char username[15];
	char password[15];
	char* temp;
	int counter=0;

	listUsers* usersList = (listUsers*)malloc(sizeof(listUsers));
	listTicket* ticketsList = (listTicket*)malloc(sizeof(listTicket));
	user* currentUser = (user*)malloc(sizeof(user));
	ticket* currentTicket = (ticket*)malloc(sizeof(ticket));
	
	getDateTime(&day, &month, &year, &hours, &mins);

	initListUsers(usersList);
	initListTickets(ticketsList);
	ReadUsers(USERS_PATH, usersList);
	ReadTickets(TICKETS_PATH, ticketsList);
	sortList(ticketsList->head);
	PrintLogo(); // Printing logo system
	while (LogIn(usersList, currentUser) != 1){
		// secure the log with limit the time of retries
		counter++;
		if (counter==3)
		{
			RedColor();
			printf("You have tried to login more than 3 times. come back later\n");
			WhiteColor();
			Logs("Unauthorized", "Log failure");
			Delay(3);
			return 1;
		}
		
	};
	Logs(currentUser,"Logging");
	printf("\n\nTime:[%02d/%02d/%d, %02d:%02d]  ,", day, month, year, hours, mins);
	LightBlue();
	removeSpaces(currentUser->fullName);
	printf("%s", currentUser->fullName);
	WhiteColor();
	printf(", Welcome to Garage System! Your level: %d \n", currentUser->level);

	/* Display Menu */
	menu(currentUser, usersList, ticketsList);

	free(usersList);
	free(ticketsList);
	//
	system("pause");
}



void getDateTime(int* day, int* month, int* year, int* hours, int* mins)
{
	time_t rawtime;
	struct tm timeinfo;

	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	*day = timeinfo.tm_mday;
	*month = timeinfo.tm_mon + 1;
	*year = timeinfo.tm_year + 1900;
	*hours = timeinfo.tm_hour;
	*mins = timeinfo.tm_min;
}

int LogIn(listUsers *lst, user* currentUser)
{
	char username[15];
	char password[15];
	struct nodeUser* tempNode;
	const ARRAY_SIZE = 15;
	tempNode = lst->head;

	printf("Log-in to your account\n");
	printf("Enter Username: ");
	scanf("%s", &username);

	printf("Enter password: ");
	scanf("%s", &password);
	system("cls"); //clear screen

	char* tempUsername = (char*)malloc(sizeof(char) * ARRAY_SIZE);
	char* tempPassword = (char*)malloc(sizeof(char) * ARRAY_SIZE);
	while (tempNode != NULL)
	{

	tempUsername = tempNode->data.userName;
	removeSpaces(tempUsername);
	tempPassword = tempNode->data.password;
	removeSpaces(tempPassword);

	if (strstr(tempUsername, username) != NULL && strstr(tempPassword, password) != NULL) {
		*currentUser = tempNode->data;
		return 1;
	}

		tempNode = tempNode->next;
	}
	return 0;
}

void menu(user* current, listUsers* usersList, listTicket* ticketsList)
{
	int menu_option, action; //MENU_OPTION - gets from client the selected menu number. ACTION - gets from the client the selected operation in selcted menu number.
	char yes_char[1]; // after the search the program ask the client - do you want update the ticket or no? 

	while (1) {
		// MENU FOR client 
		printf("\n //////////////CAR SYSTEM MENU////////////////\n");
		printf("\n *	[1] Search car ticket           *\n");
		printf("\n *	[2] Add car ticket              *\n");
		if (current->level>1){
		printf("\n *	[3] Edit car ticket             *\n");
		printf("\n *	[4] Delete car ticket           *\n");
		}
		if (current->level==3){
		printf("\n *	[5] Admin area                  *\n");
		}
		GreenColor();
		printf("\n Please select your action [1-5]. to exit press [0]: ");
		WhiteColor();
		scanf("%d", &menu_option);

		switch (menu_option) {
		// exit program
		case 0: {
			printf("Good bye!\n");
			Delay(3);
			return 1;
			break;
		}
		//Search cars (Menu option)
		case 1: {
			printf("\n==================================================================\n");
			GreenColor();
			printf("choose searching by MODEL [1] or STATUS [2] or BOTH [3] or DATE [4] or PRICE [5] or COLOR [6]. to Exit press 0.\n");
			WhiteColor();
			printf("enter your option: ");
			scanf("%d", &action);
			// Check for chosen action (search car menu option)

			switch (action)
			{
				// Go back to main menu
				case 0: {
					GreenColor();
					printf("[Message]: ");
					WhiteColor();
					printf("Exit to menu.\n");
					Delay (2); // time to see the message
					system("cls"); // clear screen
					break;
				}
				// Search MODEL
				case 1: {
						GreenColor();
						printf("[Message]: ");
						WhiteColor();
						printf("You selected option number [1]\n");
						Delay (2); // time to see the message
						system("cls"); // clear screen
						printf("Search by model\n");
						SearchByModel(ticketsList);
						Logs(current->userName, "Search");
						GreenColor();
						printf("\n\n[Message]: ");
						WhiteColor();
						printf("to update ticket write the letter 'y'. to exit type any other key: ");
						scanf("%s", &yes_char);
						// lets check what the client wants. update ticket? or no
						if(strcmp(yes_char, "y") == 0){
							printf("\n Please wait.");
							Delay(1);
							printf(".\n\n");
							UpdateTicket(ticketsList);
							Logs(current->userName, "Create Ticket");
						}
					break;
				}
				// Search  STATUS
				case 2: {
					GreenColor();
					printf("[Message]: ");
					WhiteColor();
					printf("You selected option number [2]\n");
					Delay (2); // time to see the message
					system("cls"); // clear screen
					printf("Search by status\n");
					GreenColor();
					printf("[Message]: ");
					WhiteColor();
					printf("[1] present sent to the customer. [0] present In the garage:\n");
					SearchByStatus(ticketsList);
					Logs(current->userName, "Search");
					GreenColor();
					printf("\n\n[Message]: ");
					WhiteColor();
					printf("to update ticket write the letter 'y'. to exit type any other key: ");
					// lets check what the client wants. update ticket? or no
					scanf("%s", &yes_char);
					if(strcmp(yes_char, "y") == 0){
						printf("\n Please wait.");
						Delay(1);
						printf(".\n\n");
						UpdateTicket(ticketsList);
						Logs(current->userName, "Create Ticket");
					}
					break;
				}
				// Search by TWO FIELDS
				case 3: {
					GreenColor();
					printf("[Message]: ");
					WhiteColor();
					printf("You selected option number [3]\n");
					Delay (2); // time to see the message
					system("cls"); // clear screen
					printf("Search by two fields\n");
					SearchByTwoFields(ticketsList);
					Logs(current->userName, "Search");
					GreenColor();
					printf("\n\n[Message]: ");
					WhiteColor();
					printf("to update ticket write the letter 'y'. to exit type any other key: ");
					// lets check what the client wants. update ticket? or no
					scanf("%s", &yes_char);
					if(strcmp(yes_char, "y") == 0){
						printf("\n Please wait.");
						Delay(1);
						printf(".\n\n");
						UpdateTicket(ticketsList);
						Logs(current->userName, "Create Ticket");
					}
					break;
				}
				// Search DATE
				case 4: {
					GreenColor();
					printf("[Message]: ");
					WhiteColor();
					printf("You selcted option number [4]\n");
					Delay (2); // time to see the message
					system("cls"); // clear screen
					printf("Search by date\n");
					SearchByDate(ticketsList);
					Logs(current->userName, "Search");
					GreenColor();
					printf("\n\n[Message]: ");
					WhiteColor();
					printf("[Message]: to update ticket write the letter 'y'. to exit type any other key: ");
					// lets check what the client wants. update ticket? or no
					scanf("%s", &yes_char);
					if(strcmp(yes_char, "y") == 0){
						printf("\n Please wait.");
						Delay(1);
						printf(".\n\n");
						UpdateTicket(ticketsList);
						Logs(current->userName, "Create Ticket");
					}
					break;
				}
				// Search PRICE
				case 5: {
					GreenColor();
					printf("[Message]: ");
					WhiteColor();
					printf("You selcted option number [5]\n");
					Delay (2);
					system("cls");
					printf("Search by price\n");
					SearchByPrice(ticketsList);
					Logs(current->userName, "Search");
					GreenColor();
					printf("\n\n[Message]: ");
					WhiteColor();
					printf("to update ticket write the letter 'y'. to exit type any other key: ");
					// lets check what the client wants. update ticket? or no
					scanf("%s", &yes_char);
					if(strcmp(yes_char, "y") == 0){
						printf("\n Please wait.");
						Delay(1);
						printf(".\n\n");
						UpdateTicket(ticketsList);
						Logs(current->userName, "Create Ticket");
					}
					break;
				}
				case 6: {
					GreenColor();
					WhiteColor();
					printf("You selcted option number [6]\n");
					Delay (2);
					system("cls");
					printf("Search by color\n");
					SearchByColor(ticketsList);
					Logs(current->userName, "Search");
					
					break;
				}
				// Invalid input from client
				default: {
					RedColor();
					printf("ERROR: Invalid number. Enter vaild number!\n");
					WhiteColor();
					printf("Re-Enter option:");
					scanf("%d", &action);
					Delay (2); // time to see the message
					system("cls"); // clear screen
					break;
				}
			}
			break;
		}

		//Add car ticket (Menu option)
		case 2: {
			printf("\n==================================================================\n");
			Delay(2);
			system("cls");
			printf("Add Car Ticket\n");
			AddTickets(TICKETS_PATH, ticketsList);
			Logs(current->userName, "Create Ticket");
			
			break;
		}
		// Edit Car tickets function (Menu option)
		case 3: {
			if (current->level>1){
				printf("\n==================================================================\n");
				Delay(2);
				system("cls");
				printf("Edit exsit car ticket\n");
				UpdateTicket(ticketsList);
				Logs(current->userName, "Edit Ticket");
				
			}
			else {
				RedColor();
				printf("You dont have PERMISSIONS. Contact with the administrator.\n");
				WhiteColor();
				Logs(current->userName, "No Permission");
				Delay (2); // time to see the message
				system("cls"); // clear screen
				return 1;
				}
			break;
		}
		// Delete Ticket (Menu option)
		case 4: {
			if (current->level>1){
				printf("\n==================================================================\n");
				Delay(2);
				system("cls");
				printf("Delete exist ticket\n");
				DeleteTicket(TICKETS_PATH, ticketsList);
				Logs(current->userName, "Delete Ticket");
				
				}
				else {
				RedColor();
				printf("You dont have PERMISSIONS. Contact with the administrator.\n");
				WhiteColor();
				Logs(current->userName, "No Permission");
				Delay (2); // time to see the message
				system("cls"); // clear screen
				return 1;
				}
			break;
			}

		//Admin Area ( Menu option)
		case 5: {
			if (current->level==3){
				printf("\n==================================================================\n");
				GreenColor();
				printf("Entring to Admin Mode.");
				Delay (1);
				printf(".\n");
				Delay (1);
				printf(".\n");
				WhiteColor();
				system("cls");
				RedColor();
				printf("Welcome to Admin area! Be careful with your operations.\n");
				WhiteColor();
				printf ("\n");
				Delay (2);
				system("cls");
				GreenColor();
				printf("\n^^^^^^^^^^^^^^^^^^Admin Area^^^^^^^^^^^^^^^^^^^^^^\n");
				WhiteColor();
				printf("[1]		Print logs                *^\n");
				printf("[2]		Print users               *^\n");
				printf("[3]		Print Car Database        *^\n");
				printf("[4]		Add new user	          *^\n");
				printf("[5]		Delete user from databse  *^\n");
				printf("To exit to main menu press [0]. Remmber you are in Admin Mode.");
				GreenColor();
				printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				WhiteColor();
				printf("\n \n");
				printf("Enter your option:");
				scanf("%d", &action);
			switch(action){
				case 0: {
					printf("\n==================================================================\n");
					GreenColor();
					printf("[Message]: ");
					WhiteColor();
					printf("Exit to menu.\n");
					Delay (2); // time to see the message
					system("cls"); // clear screen
					break;
				}
				//print logs function
				case 1: {
					printf("\n==================================================================\n");
					printf("Printing logs... Please wait");
					Delay (1); // time to see the message
					printf(".");
					Delay (1); // time to see the message
					printf(".\n");
					Delay (1); // time to see the message
					printf(".\n");
					system("cls"); // clear screen
					PrintLogs(); // calling to print log function
					break;
				}
				//print users function
				case 2: {
					printf("\n==================================================================\n");
					printf("Printing users table... Please wait");
					Delay (1); // time to see the message
					printf(".");
					Delay (1); // time to see the message
					printf(".\n");
					Delay (1); // time to see the message
					printf(".\n");
					system("cls"); // clear screen
					PrintUsers(); // calling to print users function
					break;
				}
				//print car database function
				case 3: {
					printf("\n==================================================================\n");
					printf("Printing car database... Please wait");
					Delay (1); // time to see the message
					printf(".");
					Delay (1); // time to see the message
					printf(".\n");
					Delay (1); // time to see the message
					printf(".\n");
					system("cls"); // clear screen
					PrintTickets(); //calling to print tickets function
					break;
				}
				// Create user
				case 4: {
					printf("\n==================================================================\n");
					Delay(2);
					system("cls"); // clear screen
					printf("create new user\n");
					AddUser(USERS_PATH, usersList);
					Logs(current->userName, "Create user");
					break;
				}
				//delete user function
				case 5: {
					printf("\n==================================================================\n");
					Delay (2);
					system("cls");//clr screen
					printf("Delete user\n");
					DeleteUser(USERS_PATH, usersList);
					Logs(current->userName, "Delete User");
					break;
				}
				default: {
					RedColor();
					printf("ERROR: Invalid number. Enter vaild number!\n");
					WhiteColor();
					printf("Re-Enter option:");
					scanf("%d", &action);
					Delay (2); // time to see the message
					system("cls"); // clear screen
					break;
				}
			}
			}
			else{
				RedColor();
				printf("You dont have PERMISSIONS. Contact with the administrator.\n");
				WhiteColor();
				Logs(current->userName, "No Permission");
				Delay (2); // time to see the message
				system("cls"); // clear screen
				return 1;
			}
			break;
		}
		}
	}
}