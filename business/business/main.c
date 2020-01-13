#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
//#include "doublyLinkedList.h"
#include "doubly_list.h"

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
void menu(int level, listUsers* tickets);

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
	//list* ticketsList = (list*)malloc(sizeof(list));
	user* currentUser = (user*)malloc(sizeof(user));

	initList(usersList);
	//initList(ticketsList);
	ReadUsers(USERS_PATH, usersList);

	while (LogIn(usersList, currentUser) != 1);
	//AddUser(USERS_PATH, lst);
	printf("Welcome to CAR SYSTEM! %s!\n", currentUser->fullName);
	//getDateTime(&day, &month, &year, &hours, &mins);
	//printf("Current computer time: %02d/%02d/%d, %02d:%02d\n", day, month, year, hours, mins);
		/* Display Menu */
	//DeleteUser(USERS_PATH, usersList);
	//menu(currentUser, ticketsList, usersList);

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


	printf("Choose username: ");
	scanf("%s", &username);

	printf("Choose password: ");
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

void menu(int level, listUsers* tickets)
{
	int menu_option, action; //MENU_OPTION - gets from client the selected menu number. ACTION - gets from the client the selected operation in selcted menu number.

	while (1) {
		// MENU FOR client
		{ 
			printf("\n //////////CAR SYSTEM MENU////////////\n");
			printf("\n *  [1] Search car ticket	           *\n");
			printf("\n *  [2] Add car ticket               *\n");
			if (level>1){
			printf("\n *  [3] Edit car ticket		       *\n");
			printf("\n *  [4] Delete car ticket			   *\n");
			}
			else if (level==3){
			printf("\n *  [5] Admin area			       *\n");
			}
			printf("\n Please select your action [1-5]. to exit press [5]:");
			scanf("%d", &menu_option);
		}

		switch (menu_option) {

		//Search cars (Menu option)
		case 1: {
			printf("choose searching by CAR NUMBER [1] or STATUS [2] or BOTH [3] or DATE [4]. to Exit press 0.\n");
			printf("enter your option: ");
			scanf("%d", &action);
			// Check for chosen action (search car menu option)
			switch (action)
			{
		    // Go back to main menu
			case 0: {
				printf("Bye Bye...\n");
				break;
			}
			// Search CAR
			case 1: {
				printf("Enter CAR number: ");
				break;
			}
			// Search  STATUS
			case 2: {
				printf("Enter STATUS: [1] sent to the customer. [0] In the garage: ");
				break;
			}
			// Search by CAR NUMBER & STATUS
			case 3: {
				printf("Enter car number: ");
				printf("Enter car status:");
				break;
			}
		    // Search DATE
			case 4: {
				printf("Enter the date you want to search for: ");
				break;
			}
			// Invalid input from client
			default: {
				printf("ERROR: Invalid number. Enter vaild number!\n");
				printf("Re-Enter option:");
				scanf("%d", &action);
			}
			}
		}

		//Add car ticket (Menu option)
		case 2: {
			printf("add new car ticket to the system");
		}
		// Edit Car tickets function (Menu option)
		case 3: {
			if (level>1){
				printf("Edit exist TICKET");
			}
			else {
				printf("You dont have PERMISSIONS. Contact with the administrator.\n");
				return 1;
				}
		}
		// Delete Ticket (Menu option)
		case 4: {
			if (level>1){
			printf("print USERS [1] or print CAR DB [2] or print LOGS[3]. To Exit press [0]\n");
			scanf("%d", &action);
			}
			else {
			printf("You dont have PERMISSIONS. Contact with the administrator.\n");
			return 1;
			}
			}

		}
		//Admin Area ( Menu option)
		case 5:{
			if (level==3){
				printf("Welcome to Admin area! Be careful with your operations.\n");
				printf("**************************************************\n");
				printf("[1] Print logs \n");
				printf("[2] Print users\n");
				printf("[3] Print Car Database\n");
				printf("[4] Change user permissions\n");
				printf("[5] Delete user from databse\n");
				printf(" Remmeber: Press 0 to exit\n");
				printf("**************************************************");
				printf("**BE CAREFUL**\n");
				printf("\n");
				printf("enter your option: ");
				scanf("%d", &action);
			switch(action){
				case 0: {
					printf("Bye Bye...\n");
					break;
				}
				//print logs function
				case 1: {
					printf("Printing logs... Please wait\n");
				}
				//print users function
				case 2: {
					printf("Printing users... Please wait\n");

				}
				//print car database function
				case 3: {
					printf("Printing car database... Please wait\n");
				}
				//change user permission function
				case 4: {
					printf("**Your'e in ADMIN MODE**\n");
				}
				//delete user function
				case 5: {
					printf("**Your'e in ADMIN MODE**\n");
				}
				default: {
					printf(" Bye Bye...\n");
					return 1;
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

