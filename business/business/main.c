#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
//#include "doublyLinkedList.h"
#include "doubly_list_users.h"
#include "doubly_list_tickets.h"
#include <stdlib.h>
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
void Search(listTicket* lst, char* path);


void menu(user* current, listUsers* tickets);

/***
* Handle function: get's the path of the users file, and print all users information.
* You may change it according to your needs.
***/

void getDateTime(int* day, int* month, int* year, int* hours, int* mins);
/***
* Handle function: Returns by referfance the current date and time
***/

void main() {

	int day, month, year, hours, mins;
	char username[15];
	char password[15];
	char* temp;

	listUsers* usersList = (listUsers*)malloc(sizeof(listUsers));
	listTicket* ticketsList = (listTicket*)malloc(sizeof(listTicket));
	user* currentUser = (user*)malloc(sizeof(user));
	ticket* currentTicket = (ticket*)malloc(sizeof(ticket));

	initListUsers(usersList);
	initListTickets(ticketsList);
	ReadUsers(USERS_PATH, usersList);
	ReadTickets(TICKETS_PATH, ticketsList);
	//Search(ticketsList, TICKETS_PATH);
	//UpdateTicket(ticketsList);
	//AddTickets(TICKETS_PATH, ticketsList);
	//DeleteTicket(TICKETS_PATH, ticketsList);
	while (LogIn(usersList, currentUser) != 1);
	//AddUser(USERS_PATH, lst);
	printf("%s, Welcome to Garage System!\n", currentUser->fullName);
	//getDateTime(&day, &month, &year, &hours, &mins);
	//printf("Current computer time: %02d/%02d/%d, %02d:%02d\n", day, month, year, hours, mins);
		/* Display Menu */
	//DeleteUser(USERS_PATH, usersList);
	menu(currentUser, usersList);

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

	printf("Log-in to your account:");
	printf("Enter Username: ");
	scanf("%s", &username);

	printf("Enter password: ");
	scanf("%s", &password);


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

void menu(user* current, listUsers* tickets)
{
	int menu_option, action; //MENU_OPTION - gets from client the selected menu number. ACTION - gets from the client the selected operation in selcted menu number.

	while (1) {
		// MENU FOR client 
		printf("\n //////////CAR SYSTEM MENU////////////\n");
		printf("\n *	[1] Search car ticket			*\n");
		printf("\n *	[2] Add car ticket				*\n");
		if (current->level>1){
		printf("\n *	[3] Edit car ticket				*\n");
		printf("\n *	[4] Delete car ticket			*\n");
		}
		if (current->level==3){
		printf("\n *	[5] Admin area					*\n");
		}
		printf("\n Please select your action [1-5]. to exit press [0]");
		scanf("%d", &menu_option);

		switch (menu_option) {

		//Search cars (Menu option)
		case 1: {
			printf("\n========================================================================================\n");
			printf("choose searching by CAR NUMBER [1] or STATUS [2] or BOTH [3] or DATE [4]. to Exit press 0.\n");
			printf("enter your option: ");
			scanf("%d", &action);
			// Check for chosen action (search car menu option)
			switch (action)
			{
				// Go back to main menu
				case 0: {
					printf("*MSG: Exit to menu.\n");
					break;
				}
				// Search CAR
				case 1: {
					printf("*MSG: You selected option number [1]\n");
					break;
				}
				// Search  STATUS
				case 2: {
					printf("*MSG: You selected option number [2]\n");
					printf("Enter STATUS: [1] present sent to the customer. [0] present In the garage:");
					break;
				}
				// Search by CAR NUMBER & STATUS
				case 3: {
					printf("*MSG: You selected option number [3]\n");
					break;
				}
				// Search DATE
				case 4: {
					printf("*MSG: You selcted option number [4]\n");
					break;
				}
				// Invalid input from client
				default: {
					printf("ERROR: Invalid number. Enter vaild number!\n");
					printf("Re-Enter option:");
					scanf("%d", &action);
					break;
				}
			}
		}

		//Add car ticket (Menu option)
		case 2: {
			printf("\n========================================================================================\n");
			break;
		}
		// Edit Car tickets function (Menu option)
		case 3: {
			if (current->level>1){
				printf("\n========================================================================================\n");
				printf("function is here");
			}
			else {
				printf("You dont have PERMISSIONS. Contact with the administrator.\n");
				return 1;
				}
			break;
		}
		// Delete Ticket (Menu option)
		case 4: {
			if (current->level>1){
				printf("\n========================================================================================\n");
				printf("Delte ticket function\n");
				}
				else {
				printf("You dont have PERMISSIONS. Contact with the administrator.\n");
				return 1;
				}
			break;
			}

		//Admin Area ( Menu option)
		case 5: {
			if (current->level==3){
				printf("\n========================================================================================\n");
				printf("Welcome to Admin area! Be careful with your operations.\n");
				printf ("\n");
				printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^Admin Area^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				printf("[1]		Print logs														^\n");
				printf("[2]		Print users														^\n");
				printf("[3]		Print Car Database												^\n");
				printf("[4]		Change user permissions											^\n");
				printf("[5]		Delete user from databse										^\n");
				printf("To exit to main menu press [0]. Remmber you are in Admin Mode.")
				printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
				printf("\n \n");
				printf("Enter your option:");
				scanf("%d", &action);
			switch(action){
				case 0: {
					printf("\n========================================================================================\n");
					printf("*MSG: Exit to menu.\n");
					break;
				}
				//print logs function
				case 1: {
					printf("\n========================================================================================\n");
					printf("Printing logs... Please wait\n");
					break;
				}
				//print users function
				case 2: {
					printf("\n========================================================================================\n");
					printf("Printing users... Please wait\n");
					break;
				}
				//print car database function
				case 3: {
					printf("\n========================================================================================\n");
					printf("Printing car database... Please wait\n");
					break;
				}
				//change user permission function
				case 4: {
					printf("\n========================================================================================\n");
					printf("Change user premission function\n");
					break;
				}
				//delete user function
				case 5: {
					printf("\n========================================================================================\n");
					printf("Delete user function \n");
					break;
				}
				default: {
					printf("ERROR: Invalid number. Enter vaild number!\n");
					printf("Re-Enter option:");
					scanf("%d", &action);
					break;
				}
			}
			}
			else{
			printf("You dont have PERMISSIONS. Contact with the administrator.\n");
			return 1;
			}
		}
		}
	}
}

