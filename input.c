#include "header.h"

void input()
{
    int choice;

    char *username = (char *)malloc(sizeof(char *));
    char *password = (char *)malloc(sizeof(char *));

    printf("Select an option:\n");
    printf("1. Sign Up \n");
    printf("2. Log in\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1)
    {
        perror("Error reading choice\n");
        exit(EXIT_FAILURE);
    }

    switch (choice)
    {
    case 1:
        registerUser(username, password);
        break;

    case 2:
        login();
        break;

    case 3:
        exit(0);
        break;

    default:
        printf("Invalid choice. Exiting.\n");
        exit(EXIT_FAILURE);
    }

    free(username);
    free(password);
}

int main()
{ 	

		
	input();
	
 	return 0;
 }
