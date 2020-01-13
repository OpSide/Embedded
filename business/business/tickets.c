//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <time.h>
//#include "doubly_list.h"
//#include <sys/stat.h>
//
//// Read user function
//void ReadTickets(char* path, list* lst)
//{
//	FILE* fp;
//	char temp[100];
//
//	fopen_s(&fp, path, "r");
//	if (!fp)
//	{
//		printf("File not found!\n");
//		return;
//	}
//
//	//header
//	fgets(temp, 100, fp);
//	puts(temp);
//	ticket tempTicket;
//	while (fscanf(fp, "%15[^\n] %15[^\n] %15[^\n]%1d\n", &tempTicket.carNumber, tempTicket.model, tempTicket.color, &tempTicket.status, tempTicket.date) > 0)
//	{
//		node* tempNode = allocItem(tempTicket);
//		insertLast(lst, tempNode);
//	}
//	Print(*lst);
//	fclose(fp);
//	return 1;
//}
//
//// Add user function
//void AddUser(char* fp_path, list* lst)
//{
//	user tempUser;
//	FILE* fp = fopen(fp_path, "a");
//	if (!fp)
//	{
//		printf("File doesnt exists\n");
//		return;
//	}
//
//	printf("Enter username: ");
//	fgets(tempUser.userName, 15, stdin);
//	tempUser.userName[strlen(tempUser.userName) - 1] = '\0';
//	printf("Enter password: ");
//	fgets(tempUser.password, 15, stdin);
//	tempUser.password[strlen(tempUser.password) - 1] = '\0';
//	printf("Enter full name ");
//	fgets(tempUser.fullName, 15, stdin);
//	tempUser.fullName[strlen(tempUser.fullName) - 1] = '\0';
//	printf("Enter level: ");
//	scanf("%1d", &tempUser.level);
//
//	node* tempNode = allocItem(tempUser);
//	fprintf(fp, "%-15s %-15s %-15s %-1d\n", tempUser.userName, tempUser.password, tempUser.fullName, tempUser.level);
//	insertLast(lst, tempNode);
//	printf("New user added!\n");
//	fclose(fp);
//}
//
//static size_t DeleteLine(char* buffer, size_t size, const char* userName)
//{
//	char* p = buffer;
//	int done = 0;
//	size_t len = strlen(userName);
//	size_t newSize = 0;
//	do
//	{
//		char* q = strstr(p, userName);
//		if (q != NULL)
//		{
//			if (strncmp(q, userName, len) == 0)
//			{
//				char* line;
//				size_t lineSize;
//				size_t restSize;
//
//				q++;
//				lineSize = 1;
//
//
//				for (line = q; *line != '\n'; ++line)
//					++lineSize;
//
//				restSize = (size_t)((buffer + size) - (q + lineSize));
//
//				memmove(q, q + lineSize, restSize);
//
//				newSize = size - lineSize;
//				done = 1;
//			}
//			else p = q + 1;
//		}
//		else
//		{
//			puts("Name doest exists");
//			done = 1;
//		}
//	} while (!done);
//
//	return newSize;
//}
//
//void DeleteUser(char* fp_path, list* lst)
//{
//	char tempUserName[14];
//	char userName[15];
//	char* uPtr;
//	struct stat st;
//	struct node* tempNode;
//
//	printf("Please username: ");
//	scanf("%s", tempUserName);
//
//	userName[0] = '\n';
//	uPtr = userName + 1;
//	strncpy(uPtr, tempUserName, 14);
//
//
//	if (stat(fp_path, &st) != -1)
//	{
//		FILE* fp = fopen(fp_path, "rb");
//		if (fp != NULL)
//		{
//			char* buffer = (char*)malloc(st.st_size);
//
//			if (fread(buffer, 1, st.st_size, fp) == st.st_size)
//			{
//				size_t newSize;
//
//				fclose(fp);
//
//				newSize = DeleteLine(buffer, st.st_size, userName);
//
//				fp = fopen(fp_path, "wb");
//				if (fp != NULL)
//				{
//					fwrite(buffer, 1, newSize, fp);
//					fclose(fp);
//				}
//				else perror(fp_path);
//			}
//			free(buffer);
//		}
//		else perror(fp_path);
//	}
//	else printf("File not found %s", fp_path);
//
//
//	tempNode = lst->head;
//	if (tempNode == NULL) return;
//	while (tempNode != NULL)
//	{
//		if (tempNode->data.userName == userName)
//		{
//			deleteLink(lst, tempNode);
//			break;
//		}
//		tempNode = tempNode->next;
//	}
//}
//
//
