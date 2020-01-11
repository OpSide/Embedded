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

	list* usersList = (list*)malloc(sizeof(list));
	list* ticketsList = (list*)malloc(sizeof(list));
	user* currentUser = (user*)malloc(sizeof(user));

	initList(usersList);
	initList(ticketsList);
	readUsers(USERS_PATH, usersList);

	while (LogIn(usersList, currentUser) != 1);
	//AddUser(USERS_PATH, lst);
	printf("Welcome %s!\n", currentUser->fullName);
	//getDateTime(&day, &month, &year, &hours, &mins);
	//printf("Current computer time: %02d/%02d/%d, %02d:%02d\n", day, month, year, hours, mins);
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

