

#include <time.h>
//#include <doubly_list.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Barak Pahima 203484217
Raviv Nachum 311453096
*/

//PRITF ALL USERS FROM ACCESS FILE
void readTickets(char* path) // txt file path
{
	FILE* fp;
	char temp[100], color[10], model[21], date[11], carId[9], phoneNumber[10], payment[5], delivered[2];
	fopen_s(&fp, path, "r");
	if (!fp)
	{
		printf("File not found!\n");
		return;
	}

	//header
	fgets(temp, 100, fp);
	puts(temp);

	while (fscanf_s(fp, "%20s %8s %1s %10s %10s %5s %5s",carId, 9, model, 21, color, 10, phoneNumber, 10, payment, 5, delivered, 2, date, 11) != EOF)
	{
		printf_s("%-20s %-8s %-1s %-10s %-10s %-5s %-5s\n", carId, model, color, phoneNumber, payment, delivered, date);
	}
	fclose(fp);
	return;
}