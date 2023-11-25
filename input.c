#include "header.h"

void input()
{
	int choice;
    	char *username = (char*) malloc (sizeof(char*)) ;
    	char *password = (char*) malloc (sizeof(char*)) ;

    	while(1){
	
	printf("Select an option:\n");
	printf("1. Sign Up \n");
	printf("2. Log in\n");
	printf("3. Exit\n");
	printf("Enter your choice: ");
	
	if (scanf("%d", &choice) != 1) {
		perror("Error reading choice\n");
		exit(EXIT_FAILURE);
	}
	if(choice == 1)
	{
		registerUser(username,password);
	}
	
	else if (choice == 2) 
	{
		login();
	
	}
	else if (choice == 3) 
	{
		exit(0);
	
	}
    	else 
    	{
        	printf("Invalid choice. Exiting.\n");
        	exit(EXIT_FAILURE);
    	}
    	}
    	free(username);
    	free(password);
}
int main()
{ 	
//printf("Count3 ");
		
	input();
//	printf("Count4 : ");
 	return 0;
 }
