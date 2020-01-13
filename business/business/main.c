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

#define ITEMS_PATH "items.txt"
/***
* This is the path where the item file is located.
***/

#define LOG_PATH "log.txt"
/***
* This is the path where the log file is located.
* Open this file and append new records into it.
***/

void readUsers(char* path, list* lst);
void AddUser(char* path, list* lst);
void menu(int level, list* tickets, list* users);
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

	list* usersList = (list*)malloc(sizeof(list));
	list* ticketsList = (list*)malloc(sizeof(list));
	user* currentUser = (user*)malloc(sizeof(user));

	initList(usersList);
	initList(ticketsList);
	readUsers(USERS_PATH, usersList);

	while (LogIn(usersList, currentUser) != 1);
	//AddUser(USERS_PATH, lst);
	printf("Welcome to CAR SYSTEM! %s!\n", currentUser->fullName);
	//getDateTime(&day, &month, &year, &hours, &mins);
	//printf("Current computer time: %02d/%02d/%d, %02d:%02d\n", day, month, year, hours, mins);
		/* Display Menu */
	
	menu(currentUser, ticketsList, usersList);

	free(usersList);
	free(ticketsList);
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

int LogIn(list *lst, user* currentUser)
{
	char username[15];
	char password[15];
	struct node* tempNode;
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

void menu(int level, list* tickets, list* users)
{
	int menu_option, action; //MENU_OPTION - gets from client the selected menu number. ACTION - gets from the client the selected operation in selcted menu number.

	while (1) {
		// MENU FOR client
		{
			printf("\n //////////CAR SYSTEM MENU////////////\n");
			printf("\n *  [1] Search car ticket	           *\n");
			printf("\n *  [2] Add car ticket              *\n");
			
			printf("\n *  [3] Edit car ticket		      *\n");
			printf("\n *  [4] Delete car ticket			  *\n");

			printf("\n *  [5] User menu			       *\n");

			printf("\n Please select your action [1-5]. to exit press [5]:");
			scanf("%d", &menu_option);
		}

		switch (menu_option) {

			//Search cars
		case 1: {
			printf("choose searching by CAR NUMBER [1] or STATUS [2] or DATE [3]. to Exit press 0.\n");
			scanf("%d", &action);
			// Invalid input from client
			if (action > 3) {
				printf("ERROR: Invalid action.\n action must be between [0] to [3]. Enter vaild action!\n");
				scanf("%d", &action);
			}
			// Check for chosen action (search car menu option)
			switch (action)
			{
				// Go back to main menu
			case 0: {
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
				  // Search DATE
			case 3: {
				printf("Enter the date you want to search for: ");
				break;
			}

			}
		}

			  //Edit cars
		case 2: {
			printf("Add NEW CAR [1] or Edit EXIST CAR [2] or Delete EXIST CAR [3]. to Exit press 0.\n");
			scanf("%d", &action);
			// Check for chosen action (edit car menu option)
			switch (action)
			{
				// Go back to main menu
			case 0: {
				break;
			}
				  // Add car
			case 1: {
				printf("Add new car to the database:");
				break;
			}
				  // Edit exist car
			case 2: {
				printf("Edit exist car from database:");
				break;
			}
				  // Delete exist car
			case 3: {
				printf("Delete exist car from database: ");
				break;
			}
			}

		}
			  // Edit users
		case 3: {
			printf("Add NEW USER [1] or Edit EXIST USER [2] or Delete EXIST USER [3]. To Exit press [0]\n");
			scanf("%d", &action);
			//Check for chosen action (edit user menu option)
			switch (action)
			{
				// Go back to main menu
			case 0: {
				break;
			}
				  // Add user
			case 1: {
				printf("Add new user to the database:");
				break;
			}
				  // Edit exist user & including permissions
			case 2: {
				printf("Edit exist user from database:");
				break;
			}
				  // Delete exist user
			case 3: {
				printf("Delete exist car user database: ");
				break;
			}
			}

			// Print reports
		case 4: {
			printf("print USERS [1] or print CAR DB [2] or print LOGS[3]. To Exit press [0]\n");
			scanf("%d", &action);
			//Check for chosen action (edit user menu option)
			switch (action)
			{
				// Go back to main menu
			case 0: {
				break;
			}
				  // print users
			case 1: {
				printf("[USERS] We are preparing the printing...");
				break;
			}
				  // print Cars DB
			case 2: {
				printf("[CARS DataBase] We are preparing the printing...");
				break;
			}
				  // print logs
			case 3: {
				printf("[LOGS] We are preparing the printing... ");
				break;
			}
			}
		}
		}
		}
	}
}
