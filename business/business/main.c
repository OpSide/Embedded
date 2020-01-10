#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include "doublyLinkedList.h"
struct Node* userListHead;
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

void readUsers(char* path, struct Node* userListHead);
void AddUser(char* path, struct Node* userListHead);

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

	readUsers(USERS_PATH, userListHead);
	
	getDateTime(&day, &month, &year, &hours, &mins);
	printf("Current computer time: %02d/%02d/%d, %02d:%02d\n", day, month, year, hours, mins);
	AddUser(USERS_PATH, userListHead);
	system("pause");
}


<<<<<<< HEAD
=======
	while (fscanf_s(fp, "%15[^\n] %15[^\n] %1d %20[^\n]", username, 16, password, 16, &level, fullname, 21) != EOF)
	{
		printf_s("%-15s %-15s %-1d %-20s\n", username, password, level, fullname);
		
	}

	fclose(fp);
	return;
}
>>>>>>> 84087bdeeaa299a7d5c727988dc7ef69dc97a340


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
