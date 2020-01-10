#include <stdio.h>
#include <time.h>

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

void readUsers(char* path);
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

	readUsers(USERS_PATH);

	getDateTime(&day, &month, &year, &hours, &mins);
	printf("Current computer time: %02d/%02d/%d, %02d:%02d\n", day, month, year, hours, mins);

	system("pause");
}

void readUsers(char* path)
{
	FILE* fp;
	int level;
	char temp[100], username[16], password[16], fullname[21];

	fopen_s(&fp, path, "r");
	if (!fp)
	{
		printf("File not found!\n");
		return;
	}

	//header
	fgets(temp, 100, fp);
	puts(temp);

	while (fscanf_s(fp, "%15[^\n] %15[^\n] %1d %20[^\n]", username, 16, password, 16, &level, fullname, 21) != EOF)
	{
		printf_s("%-15s %-15s %-1d %-20s\n", username, password, level, fullname);
	}

	fclose(fp);
	return;
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
