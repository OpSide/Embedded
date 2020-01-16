#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include "doubly_list_tickets.h"
#include <sys/stat.h>

#define TICKETS_PATH "tickets.txt"
void Search(listTicket* lst, char* path,int searchOption,char* operand)
{
	FILE* fp;
	nodeTickets* nodeTicket;
	nodeTickets* tempNode = NULL;

	nodeTicket = lst->head;
	char userInput[16], userInput2[16], temp[100];
	char tempString[16], tempString2[16];
	switch (searchOption)
	{
		case 1:
		{
			printf("Enter car number: ");
			fgets(tempString, 15, stdin);
			tempString[strlen(tempString) - 1] = '\0';
			printf("Enter model: ");
			fgets(tempString2, 15, stdin);
			tempString[strlen(tempString) - 1] = '\0';

			strncpy(tempString, nodeTicket->data.carNumber);
			strncpy(tempString2, nodeTicket->data.color);
		}
		case 2:
		{
			printf("Enter price: ");
			fgets(tempString, 15, stdin);
			tempString[strlen(tempString) - 1] = '\0';

			strncpy(tempString, nodeTicket->data.carNumber);
		}
		case 3:
		{
			printf("Enter car status: ");
			fgets(tempString, 15, stdin);
			tempString[strlen(tempString) - 1] = '\0';

			strncpy(tempString, nodeTicket->data.carNumber);
		}
		case 4:
		{
			printf("Enter date: ");
			fgets(tempString, 15, stdin);
			tempString[strlen(tempString) - 1] = '\0';


			strncpy(tempString, nodeTicket->data.carNumber);
		}
	}
	printf("\nEnter car number.  \nCar number: ");
	scanf("%s", userInput);

	fopen_s(&fp, path, "r");
	if (!fp)
	{
		printf("\n\nFile not found!\n");
		return;
	}

	fgets(temp, 100, fp);
	printf("%s", temp);

	while (nodeTicket != NULL)
	{
		if (atoi(userInput) == nodeTicket->data.carNumber)
		{
			tempNode = nodeTicket;
			printf("%-7d         %-15s %-15s %-15s %-1d\n", nodeTicket->data.carNumber, nodeTicket->data.model, nodeTicket->data.color, nodeTicket->data.date, nodeTicket->data.status);
		}
		nodeTicket = nodeTicket->next;
	}
	if (tempNode == NULL)
	{
		printf("Car not found in DB\n");
	}
	fclose(fp);
}
void saveTicketsToFile(listTicket* lst ,char* path)
{
	FILE* fp;

	fopen_s(&fp, path, "w"); //Erase old data

	nodeTickets* current = lst->head;
	fprintf_s(fp, "%-15s%-15s%-15s%-15s%-15s%-15s\n", "carnumber", "model", "color", "date","price", "status");
	for (current; current != NULL; current = current->next)
	{
		fprintf_s(fp, "%-7d        %-15s%-15s%-15s%-4d           %-1d\n", current->data.carNumber, current->data.model, current->data.color, current->data.date,current->data.price, current->data.status);
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

	//header
	fgets(temp, 100, fp);
	puts(temp);
	ticket tempTicket;
	while (fscanf(fp, "%7d %15[^\n] %15[^\n] %15[^\n]%15d%1d\n", &tempTicket.carNumber, tempTicket.model, tempTicket.color,  tempTicket.date,&tempTicket.price ,&tempTicket.status) > 0)
	{
		nodeTickets* tempNode = allocItemTickets(tempTicket);
		insertLastTickets(lst, tempNode);
	}
	PrintTickets(*lst);
	fclose(fp);
	return 1;
}

// Add ticket function
void AddTickets(char* fp_path, listTicket* lst)
{
	ticket tempTicket;
	FILE* fp = fopen(fp_path, "a");
	if (!fp)
	{
		printf("File doesnt exists\n");
		return;
	}

	printf("Enter car number: ");
	scanf("%d", &tempTicket.carNumber);
	printf("Enter status: ");
	scanf("%d", &tempTicket.status);
	printf("Enter price: ");
	scanf("%d", &tempTicket.price);
	getchar();
	printf("Enter model ");
	fgets(tempTicket.model, 15, stdin);
	tempTicket.model[strlen(tempTicket.model) - 1] = '\0';
	printf("Enter color: ");
	fgets(tempTicket.color, 15, stdin);
	tempTicket.color[strlen(tempTicket.color) - 1] = '\0';
	printf("Enter date: ");
	fgets(tempTicket.date, 15, stdin);
	tempTicket.date[strlen(tempTicket.date) - 1] = '\0';

	nodeTickets* tempNode = allocItemTickets(tempTicket);
	fprintf(fp, "%-7d        %-15s%-15s%-15s%-4d           %-1d\n", tempTicket.carNumber, tempTicket.model, tempTicket.color, tempTicket.date,tempTicket.price, tempTicket.status);
	insertLastTickets(lst, tempNode);
	printf("New ticket added!\n");
	fclose(fp);
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
			puts("Name doest exists");
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

	printf("Please enter car number: ");
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


