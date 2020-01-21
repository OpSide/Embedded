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
#include "doubly_list_users.h"
#include "doubly_list_tickets.h"
#include <stdlib.h>
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
// void PrintFiles (char log_file_name){
// 	 FILE *fptr; 
    
// 	char c; 
//     // Open file
// 	//fopen_s(&fptr, LOG_PATH, "r");
//     fptr = fopen(log_file_name, "r"); 
//     if (fptr == NULL) 
//     { 
//         printf("Cannot open file. Contact with the administrator \n"); 
//         exit(0); 
//     } 
  
//     // Read contents from file 
//     c = fgetc(fptr); 
//     while (c != EOF) 
//     { 
//         printf ("\n %c \n", c); 
//         c = fgetc(fptr); 
//     } 
  
//     fclose(fptr); 
    
// }
void main() {

	int day, month, year, hours, mins;
	char username[15];
	char password[15];
	char* temp;

	listUsers* usersList = (listUsers*)malloc(sizeof(listUsers));
	listTicket* ticketsList = (listTicket*)malloc(sizeof(listTicket));
	user* currentUser = (user*)malloc(sizeof(user));
	ticket* currentTicket = (ticket*)malloc(sizeof(ticket));
	
	getDateTime(&day, &month, &year, &hours, &mins);

	initListUsers(usersList);
	initListTickets(ticketsList);
	ReadUsers(USERS_PATH, usersList);
	ReadTickets(TICKETS_PATH, ticketsList);

	while (LogIn(usersList, currentUser) != 1);
	Logs(currentUser,"Logging");
	//AddUser(USERS_PATH, lst);
	printf("Time:[%02d/%02d/%d, %02d:%02d],  %s, Welcome to Garage System! Your level: %d \n", day, month, year, hours, mins, currentUser->fullName, currentUser->level);

	/* Display Menu */
	menu(currentUser, usersList, ticketsList);

	free(usersList);
	//free(ticketsList);
	system("pause");
}
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
		printf("\n Please select your action [1-5]. to exit press [0]");
		scanf("%d", &menu_option);

		switch (menu_option) {

		//Search cars (Menu option)
		case 1: {
			printf("\n==================================================================\n");
			printf("choose searching by MODEL [1] or STATUS [2] or BOTH [3] or DATE [4] or PRICE [5] or COLOR [6]. to Exit press 0.\n");
			printf("enter your option: ");
			scanf("%d", &action);
			// Check for chosen action (search car menu option)

			switch (action)
			{
				// Go back to main menu
				case 0: {
					printf("[Message]: Exit to menu.\n");
					Delay (2); // time to see the message
					system("cls"); // clear screen
					break;
				}
				// Search MODEL
				case 1: {
						printf("[Message]: You selected option number [1]\n");
						Delay (2); // time to see the message
						system("cls"); // clear screen
						SearchByModel(ticketsList);
						Logs(current->userName, "Search");
						free(ticketsList);
					break;
				}
				// Search  STATUS
				case 2: {
					printf("[Message]: You selected option number [2]\n");
					Delay (2); // time to see the message
					system("cls"); // clear screen
					printf("[Message]: [1] present sent to the customer. [0] present In the garage:\n");
					SearchByStatus(ticketsList);
					Logs(current->userName, "Search");
					free(ticketsList);
					break;
				}
				// Search by TWO FIELDS
				case 3: {
					printf("[Message]: You selected option number [3]\n");
					Delay (2); // time to see the message
					system("cls"); // clear screen
					SearchByTwoFields(ticketsList);
					Logs(current->userName, "Search");
					free(ticketsList);
					break;
				}
				// Search DATE
				case 4: {
					printf("[Message]: You selcted option number [4]\n");
					Delay (2); // time to see the message
					system("cls"); // clear screen
					SearchByDate(ticketsList);
					Logs(current->userName, "Search");
					free(ticketsList);
					break;
				}
				// Search PRICE
				case 5: {
					printf("[Message]: You selcted option number [5]\n");
					Delay (2);
					system("cls");
					SearchByPrice(ticketsList);
					Logs(current->userName, "Search");
					free(ticketsList);
				}
				case 6: {
					printf("[Message]: You selcted option number [6]\n");
					Delay (2);
					system("cls");
					SearchByColor(ticketsList);
					Logs(current->userName, "Search");
					free(ticketsList);
				}
				// Invalid input from client
				default: {
					printf("ERROR: Invalid number. Enter vaild number!\n");
					printf("Re-Enter option:");
					scanf("%d", &action);
					Delay (2); // time to see the message
					system("cls"); // clear screen
					break;
				}
			}
		}

		//Add car ticket (Menu option)
		case 2: {
			printf("\n==================================================================\n");
			printf("Add Car Ticket");
			Delay(2);
			system("cls");
			AddTickets(TICKETS_PATH, ticketsList);
			Logs(current->userName, "Create Ticket");
			free(ticketsList);
			break;
		}
		// Edit Car tickets function (Menu option)
		case 3: {
			if (current->level>1){
				printf("\n==================================================================\n");
				printf("Edit exsit car ticket\n");
				Delay(2);
				system("cls");
				UpdateTicket(ticketsList);
				Logs(current->userName, "Edit Ticket");
				free(ticketsList);
			}
			else {
				printf("You dont have PERMISSIONS. Contact with the administrator.\n");
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
				printf("Delete exist ticket\n");
				Delay(2);
				system("cls");
				DeleteTicket(TICKETS_PATH, ticketsList);
				Logs(current->userName, "Delete Ticket");
				free(ticketsList);
				}
				else {
				printf("You dont have PERMISSIONS. Contact with the administrator.\n");
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
				printf("Entring to Admin Mode.");
				Delay (1);
				printf(".\n");
				Delay (1);
				printf(".\n");
				system("cls");
				printf("Welcome to Admin area! Be careful with your operations.\n");
				printf ("\n");
				Delay (1);
				system("cls");
				printf("\n^^^^^^^^^^^^^^^^^^Admin Area^^^^^^^^^^^^^^^^^^^^^^\n");
				printf("[1]		Print logs                *^\n");
				printf("[2]		Print users               *^\n");
				printf("[3]		Print Car Database        *^\n");
				printf("[4]		Add new user	          *^\n");
				printf("[5]		Delete user from databse  *^\n");
				printf("To exit to main menu press [0]. Remmber you are in Admin Mode.");
				printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				printf("\n \n");
				printf("Enter your option:");
				scanf("%d", &action);
			switch(action){
				case 0: {
					printf("\n==================================================================\n");
					printf("[Message]: Exit to menu.\n");
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
					system("cls"); // clear screen
					//PrintFiles("LOG_PATH");
					break;
				}
				//print users function
				case 2: {
					printf("\n==================================================================\n");
					printf("Printing users... Please wait");
					Delay (1); // time to see the message
					printf(".");
					Delay (1); // time to see the message
					printf(".\n");
					system("cls"); // clear screen
					//PrintFiles("USERS_PATH");
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
					system("cls"); // clear screen
					//PrintFiles("TICKETS_CAR");
					break;
				}
				// Create user
				case 4: {
					printf("\n==================================================================\n");
					printf("create user\n");
					Delay(2);
					system("cls"); // clear screen
					AddUser(USERS_PATH, usersList);
					Logs(current->userName, "Create user");
					free(usersList);
					break;
				}
				//delete user function
				case 5: {
					printf("\n==================================================================\n");
					printf("Delete user\n");
					Delay (2);
					system("cls");//clr screen
					DeleteUser(USERS_PATH, usersList);
					Logs(current->userName, "Delete User");
					free(usersList);
					break;
				}
				default: {
					printf("ERROR: Invalid number. Enter vaild number!\n");
					printf("Re-Enter option:");
					scanf("%d", &action);
					Delay (2); // time to see the message
					system("cls"); // clear screen
					break;
				}
			}
			}
			else{
				printf("You dont have PERMISSIONS. Contact with the administrator.\n");
				Logs(current->userName, "No Permission");
				Delay (2); // time to see the message
				system("cls"); // clear screen
				return 1;
			}
		}
		}
	}
}