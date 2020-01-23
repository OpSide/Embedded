#include <stdio.h>
#include <stdlib.h>

#define USERS_PATH "users.txt"

#define LOG_PATH "log.txt"

#define TICKETS_PATH "tickets.txt"

#define LOGO_PATH "logo.txt"
//LOGS
 int PrintLogs (){
 	 FILE *fptr; 
 	char c; 
     // Open file
    fptr = fopen(LOG_PATH, "r"); 
     if (fptr == NULL) 
     { 
         printf("Cannot open Logs file. Contact with the administrator \n"); 
         exit(0); 
     } 

      printf("\n\n");
     // Read contents from file 
     c = fgetc(fptr); 
     while (c != EOF) 
     { 
         printf ("%c", c); 
         c = fgetc(fptr); 
     } 
  
     fclose(fptr); 
    printf("\n");
    printf("\n");      
 }

 //USERS
 int PrintUsers (){
 	 FILE *fptr; 
 	char c; 
     // Open file
    fptr = fopen(USERS_PATH, "r"); 
     if (fptr == NULL) 
     { 
         printf("Cannot open Users file. Contact with the administrator \n"); 
         exit(0); 
     } 
     
      printf("\n\n");
     // Read contents from file 
     c = fgetc(fptr); 
     while (c != EOF) 
     { 
         printf ("%c", c); 
         c = fgetc(fptr); 
     } 
  
     fclose(fptr); 
    printf("\n");
    printf("\n");    
 }

  //TICKETS
 int PrintTickets (){
 	 FILE *fptr; 
 	char c; 
     // Open file
    fptr = fopen(TICKETS_PATH, "r"); 
     if (fptr == NULL) 
     { 
         printf("Cannot open Tickets file. Contact with the administrator \n"); 
         exit(0); 
     } 
    
     printf("\n\n");
     // Read contents from file 
     c = fgetc(fptr); 
     while (c != EOF) 
     { 
         printf ("%c", c); 
         c = fgetc(fptr); 
     } 
  
     fclose(fptr); 
    printf("\n");
    printf("\n");   
 }

  //LOGO
 int PrintLogo (){
 	 FILE *fptr; 
 	char c; 
     // Open file
    fptr = fopen(LOGO_PATH, "r"); 
     if (fptr == NULL) 
     { 
         printf("Oops...Cannot Print System log\n"); 
         exit(0); 
     } 
    
      printf("\n\n\n");
     // Read contents from file 
     c = fgetc(fptr); 
     while (c != EOF) 
     { 
         printf ("%c", c); 
         c = fgetc(fptr); 
     } 
     fclose(fptr); 
    printf("\n\n\n");
 }