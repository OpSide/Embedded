#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include "doublyLinkedList.h"


void readUsers(char* path,struct Node* userListHead)
{
	struct Node* userCurrent;
	FILE* fp;
	user tempUser;
	int level;
	char temp[100], username[16], password[16], fullname[16];

	fopen_s(&fp, path, "r");
	if (!fp)
	{
		printf("File not found!\n");
		return;
	}
	userListHead = NULL;

	//header
	fgets(temp, 100, fp);
	puts(temp);

	while (fscanf(fp, "%15[^\n] %15[^\n] %15[^\n]%1d", tempUser.userName, tempUser.password, tempUser.fullName, &tempUser.level) > 0)
	{
		InsertAtTail(&userListHead, tempUser);
	}
	Print(&userListHead);
	userCurrent = userListHead;
	fclose(fp);
	return 1;
}

void AddUser(char *fp_path, struct Node* userListHead)
{
	user tempUser;
	FILE* fp = fopen(fp_path, "a");
	if (!fp)
	{
		printf("File doesnt exists\n");
		return;
	}

	printf("Enter username: ");
	fgets(tempUser.userName, 15, stdin);
	tempUser.userName[strlen(tempUser.userName) - 1] = '\0';
	printf("Enter password: ");
	fgets(tempUser.password, 15, stdin);
	tempUser.password[strlen(tempUser.password) - 1] = '\0';
	printf("Enter full name ");
	fgets(tempUser.fullName, 15, stdin);
	tempUser.fullName[strlen(tempUser.fullName) - 1] = '\0';
	printf("Enter level: ");
	scanf("%1d", &tempUser.level);


	fprintf(fp, "%-15s %-15s %-15s %-1d\n", tempUser.userName, tempUser.password, tempUser.fullName, tempUser.level);
	InsertAtTail(&userListHead, tempUser);
	printf("New user added!\n");
	fclose(fp);
}