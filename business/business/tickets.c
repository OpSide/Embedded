/////////////////////////////////////
//		Copyrights (C) to	   /////
//		   January 2020		  /////
//*/ Raviv Nachum ID 311453096  //
//*/ Barak Pahima ID 203484217 //
////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include "doubly_list_tickets.h"
#include <sys/stat.h>
#include <time.h>

void sortList(nodeTickets* head);

#define TICKETS_PATH "tickets.txt"

void SearchByTwoFields(listTicket* lst)
{
	char str1[16], str2[16];
	nodeTickets* tempNode;

	printf("Enter model: ");
	getchar();
	fgets(str2, 15, stdin);
	str2[strlen(str2) - 1] = '\0';
	printf("Enter color: ");
	fgets(str1, 15, stdin);
	str1[strlen(str1) - 1] = '\0';

	tempNode = lst->head;
	if (tempNode == NULL) return;

	while (tempNode != NULL)
	{
	removeSpaces(&tempNode->data.color);	
	removeSpaces(&tempNode->data.model);
		if (strncmp(&tempNode->data.color, str1) == 0 && strncmp(tempNode->data.model , str2) == 0)
		{
			printf("Car found!\n");
			printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "carnumber", "model", "color", "date", "price", "status");
			printf("%-7d        %-15s%-15s%-15s%-4d           %-1d\n", tempNode->data.carNumber, tempNode->data.model, tempNode->data.color, tempNode->data.date, tempNode->data.price, tempNode->data.status);
			break;
		}

		tempNode = tempNode->next;
	}
}

void SearchByModel(listTicket* lst)
{

	char  str2[16];
	nodeTickets* tempNode;

	printf("Enter model: ");
	getchar();
	fgets(str2, 15, stdin);
	str2[strlen(str2) - 1] = '\0';

	tempNode = lst->head;
	if (tempNode == NULL) return;

	while (tempNode != NULL)
	{
	removeSpaces(&tempNode->data.model);
		if (strncmp(tempNode->data.model, str2) == 0)
		{
			printf("Car found!\n");
			printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "carnumber", "model", "color", "date", "price", "status");
			printf("%-7d        %-15s%-15s%-15s%-4d           %-1d\n", tempNode->data.carNumber, tempNode->data.model, tempNode->data.color, tempNode->data.date, tempNode->data.price, tempNode->data.status);
			break;
		}

		tempNode = tempNode->next;
	}

}

void SearchByColor(listTicket* lst)
{

	char  str2[16];
	nodeTickets* tempNode;

	printf("Enter color: ");
	getchar();
	fgets(str2, 15, stdin);
	str2[strlen(str2) - 1] = '\0';


	tempNode = lst->head;
	if (tempNode == NULL) return;

	while (tempNode != NULL)
	{
	removeSpaces(&tempNode->data.color);
		if (strncmp(tempNode->data.color, str2) == 0)
		{
			printf("Car found!\n");
			printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "carnumber", "model", "color", "date", "price", "status");
			printf("%-7d        %-15s%-15s%-15s%-4d           %-1d\n", tempNode->data.carNumber, tempNode->data.model, tempNode->data.color, tempNode->data.date, tempNode->data.price, tempNode->data.status);
			break;
		}

		tempNode = tempNode->next;
	}

}

void SearchByPrice(listTicket* lst)
{

	int price, opt;
	char operand;
	nodeTickets* tempNode;
	printf("Please select [1] to search by greater then or [2] to search by less then\n");
	scanf("%d", &opt);
	if (opt != 1 && opt != 2)
	{
		printf("Wrong input");
		return 0;
	}

	printf("Enter price: \n");
	scanf("%d", &price);

	tempNode = lst->head;
	if (tempNode == NULL) return 0;

		printf("%-15s%-15s%-15s%-15s%-15s%-15s\n", "carnumber", "model", "color", "date", "price", "status");
	while (tempNode != NULL)
	{
		if (opt == 1) {
			if (price < tempNode->data.price)
			{
				printf("%-7d        %-15s%-15s%-15s%-4d           %-1d\n", tempNode->data.carNumber, tempNode->data.model, tempNode->data.color, tempNode->data.date, tempNode->data.price, tempNode->data.status);
			}
		}
		else if (opt == 2) {
			if (price > tempNode->data.price)
			{
				printf("%-7d        %-15s%-15s%-15s%-4d           %-1d\n", tempNode->data.carNumber, tempNode->data.model, tempNode->data.color, tempNode->data.date, tempNode->data.price, tempNode->data.status);
			}
		}
		tempNode = tempNode->next;
	}
}

void SearchByStatus(listTicket* lst)
{
	int status;
	nodeTickets* tempNode;


	printf("Enter status to search: \n");
	scanf("%d", &status);
	if (status != 0 && status != 1) {
		printf("Wrong input");
		return 0;
	}
	tempNode = lst->head;
	if (tempNode == NULL) return 0;

	printf("%-15s%-15s%-15s%-15s%-15s%-15s\n\n", "carnumber", "model", "color", "date", "price", "status");
	while (tempNode != NULL)
	{
		if (status == tempNode->data.status)
		{
			printf("%-7d        %-15s%-15s%-15s%-4d           %-1d\n", tempNode->data.carNumber, tempNode->data.model, tempNode->data.color, tempNode->data.date, tempNode->data.price, tempNode->data.status);
		}
		tempNode = tempNode->next;
	}
}

void SearchByDate(listTicket* lst)
{
	char date[16];
	int opt;
	nodeTickets* tempNode;
	printf("Please select [1] to search by greater then or [2] to search by less then\n");
	scanf("%d", &opt);
	if (opt != 1 && opt != 2)
	{
		printf("Wrong input");
		return 0;
	}

	printf("Enter date with the following syntax: DD-MM-YYYY: \n");
	getchar();
	fgets(date, 15, stdin);
	date[strlen(date) - 1] = '\0';
	
	tempNode = lst->head;
	if (tempNode == NULL) return 0;

	printf("%-15s%-15s%-15s%-15s%-15s%-15s\n\n", "carnumber", "model", "color", "date", "price", "status");
	while (tempNode != NULL)
	{
		removeSpaces(tempNode->data.date);
		if (opt == 1) {
			if (strncmp(tempNode->data.date, date) > 0)
			{
				printf("%-7d        %-15s%-15s%-15s%-4d           %-1d\n", tempNode->data.carNumber, tempNode->data.model, tempNode->data.color, tempNode->data.date, tempNode->data.price, tempNode->data.status);
			}
		}
			else if (opt == 2) {
				if (strncmp(tempNode->data.date, date) < 0)
				{
				printf("%-7d        %-15s%-15s%-15s%-4d           %-1d\n", tempNode->data.carNumber, tempNode->data.model, tempNode->data.color, tempNode->data.date, tempNode->data.price, tempNode->data.status);
				}
			}
		tempNode = tempNode->next;
		}
}


void saveTicketsToFile(listTicket* lst ,char* path)
{
	FILE* fp;
	sortList(lst->head);
	fopen_s(&fp, path, "w"); //Erase old data

	nodeTickets* current = lst->head;
	fprintf_s(fp, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "carnumber", "model", "color", "date","price", "status");
	while(current != NULL)
	{
		fprintf_s(fp, "%-7d        %-15s%-15s%-15s%-4d           %-1d\n", current->data.carNumber, current->data.model, current->data.color, current->data.date,current->data.price, current->data.status);
		current = current->next;
	}

	fclose(fp);
}
//Updates ticket
void UpdateTicket(listTicket* lst) {
	char tempCarNumber[14];
	char carNumber[15];
	char* uPtr;
	struct stat st;
	struct nodeTickets* tempNode;

	printf("Please enter car number to update: ");
	scanf("%s", tempCarNumber);

	carNumber[0] = '\n';
	uPtr = carNumber + 1;
	strncpy(uPtr, tempCarNumber, 14);

	tempNode = lst->head;
	if (tempNode == NULL) return;
	while (tempNode != NULL)
	{
		if (tempNode->data.carNumber == atoi(carNumber))
		{
			printf("Car found!, please update the ticket\n");
			break;
		}

		tempNode = tempNode->next;
	}

	if (tempNode != NULL) {
		printf("Enter car number: ");
		scanf("%d", &tempNode->data.carNumber);
		printf("Enter status: ");
		scanf("%d", &tempNode->data.status);
		printf("Enter price: ");
		scanf("%d", &tempNode->data.price);
		getchar();
		printf("Enter model ");
		fgets(tempNode->data.model, 15, stdin);
		tempNode->data.model[strlen(tempNode->data.model) - 1] = '\0';
		printf("Enter color: ");
		fgets(tempNode->data.color, 15, stdin);
		tempNode->data.color[strlen(tempNode->data.color) - 1] = '\0';
		printf("Enter date: ");
		fgets(tempNode->data.date, 15, stdin);
		tempNode->data.date[strlen(tempNode->data.date) - 1] = '\0';
	}
	saveTicketsToFile(lst, TICKETS_PATH);
}
// Read ticket function
void ReadTickets(char* path, listTicket* lst)
{
	FILE* fp;
	char temp[100];

	fopen_s(&fp, path, "r");
	if (!fp)
	{
		printf("File not found!\n");
		return;
	}
	fgets(temp, 100, fp);

	ticket tempTicket;
	while (fscanf(fp, "%7d %15[^\n] %15[^\n] %15[^\n]%15d%1d\n", &tempTicket.carNumber, tempTicket.model, tempTicket.color,  tempTicket.date,&tempTicket.price ,&tempTicket.status) > 0)
	{
		nodeTickets* tempNode = allocItemTickets(tempTicket);
		insertLastTickets(lst, tempNode);
	}
	fclose(fp);
	return 1;
}

// Add ticket function
void AddTickets(char* fp_path, listTicket* lst)
{
	ticket tempTicket;
	//FILE* fp = fopen(fp_path, "a");
	//if (!fp)
	//{
	//	printf("File doesnt exists\n");
	//	return;
	//}

	printf("Enter car number: ");
	scanf("%d", &tempTicket.carNumber);
	printf("Enter status: ");
	scanf("%d", &tempTicket.status);
	printf("Enter price: ");
	scanf("%d", &tempTicket.price);
	getchar();
	printf("Enter model: ");
	fgets(tempTicket.model, 15, stdin);
	tempTicket.model[strlen(tempTicket.model) - 1] = '\0';
	printf("Enter color: ");
	fgets(tempTicket.color, 15, stdin);
	tempTicket.color[strlen(tempTicket.color) - 1] = '\0';
	printf("Enter date in the following format DD-MM-YYYY: ");
	fgets(tempTicket.date, 15, stdin);
	tempTicket.date[strlen(tempTicket.date) - 1] = '\0';

	nodeTickets* tempNode = allocItemTickets(tempTicket);
	insertLastTickets(lst, tempNode);
	saveTicketsToFile(lst, TICKETS_PATH);
	printf("New ticket added!\n");
	//fclose(fp);
}

static size_t DeleteLine(char* buffer, size_t size, const char* carNumber)
{
	char* p = buffer;
	int done = 0;
	size_t len = strlen(carNumber);
	size_t newSize = 0;
	do
	{
		char* q = strstr(p, carNumber);
		if (q != NULL)
		{
			if (strncmp(q, carNumber, len) == 0)
			{
				char* line;
				size_t lineSize;
				size_t restSize;

				q++;
				lineSize = 1;


				for (line = q; *line != '\n'; ++line)
					++lineSize;

				restSize = (size_t)((buffer + size) - (q + lineSize));

				memmove(q, q + lineSize, restSize);

				newSize = size - lineSize;
				done = 1;
			}
			else p = q + 1;
		}
		else
		{
			puts("Name doesnt exists");
			done = 1;
		}
	} while (!done);

	return newSize;
}

void DeleteTicket(char* fp_path, listTicket* lst)
{
	char tempCarNumber[14];
	char carNumber[15];
	char* uPtr;
	struct stat st;
	struct nodeTickets* tempNode;

	printf("Enter car number: ");
	scanf("%s", tempCarNumber);

	carNumber[0] = '\n';
	uPtr = carNumber + 1;
	strncpy(uPtr, tempCarNumber, 14);


	if (stat(fp_path, &st) != -1)
	{
		FILE* fp = fopen(fp_path, "rb");
		if (fp != NULL)
		{
			char* buffer = (char*)malloc(st.st_size);

			if (fread(buffer, 1, st.st_size, fp) == st.st_size)
			{
				size_t newSize;

				fclose(fp);

				newSize = DeleteLine(buffer, st.st_size, carNumber);

				fp = fopen(fp_path, "wb");
				if (fp != NULL)
				{
					fwrite(buffer, 1, newSize, fp);
					fclose(fp);
				}
				else perror(fp_path);
			}
			free(buffer);
		}
		else perror(fp_path);
	}
	else printf("File not found %s", fp_path);


	tempNode = lst->head;
	if (tempNode == NULL) return;
	while (tempNode != NULL)
	{
		if (tempNode->data.carNumber == atoi(carNumber))
		{
			deleteLinkTickets(lst, tempNode);
			break;
		}
		tempNode = tempNode->next;
	}
}


