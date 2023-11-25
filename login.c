#include "header.h"

void userlogin(char *buftoken)
{
	
	int choice;
	static int count2=0;
	while (1){
		printf("1: Bidding\n");
		printf("2: Selling\n");
		printf("3: Sign Out\n");
		
		printf("Enter your choice: ");
		if (scanf("%d", &choice) != 1) 
		{
			perror("Error reading choice\n");
			exit(EXIT_FAILURE);
		}
		if (choice == 1) 
		{
			
			printf("Count1 : %d\n",count2);
			Bidding(buftoken,count2);
			
		}
		else if (choice == 2) 
		{	count2++;
			createNewAuction(buftoken);
		}
		else if (choice == 3) 
		{
			//input();
			return;
		}
		else 
	    	{
			printf("Invalid choice. Exiting.\n");
			exit(EXIT_FAILURE);
	    	}
	    }
}
void login() {
	// Create an instance of the User struct and initialize it with predefined values
	struct User user1;


	// Allocate memory for username and password
	user1.username = (char *)malloc(MAX_USERNAME * sizeof(char));
	user1.password = (char *)malloc(MAX_PASSWORD * sizeof(char));

	// Check if memory allocation is successful
	if (user1.username == NULL || user1.password == NULL) 
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	int fd = open("Usernamelist.txt", O_RDONLY);
	if (fd == -1) 
	{
		perror("Failed to open Usernamelist.txt\n");
		exit(EXIT_FAILURE);
	}



	char** buftoken = parse_cmd(fd);

	// Prompt the user to enter credentials
	char enteredUsername[MAX_USERNAME];
	char enteredPassword[MAX_PASSWORD];
	int validCredentials = 0;

	// Allow multiple login attempts
	while (1) {
	// Initialize validCredentials to 0 before each attempt
	validCredentials = 0;

	printf("Enter username: ");
	scanf("%s", enteredUsername);

	printf("Enter password: ");
	scanf("%s", enteredPassword);
	getchar();

	// Check if the entered credentials are in the file
	for (int i=0 ; buftoken[i] != '\0'; i += 2) {
	    if (strcmp(buftoken[i], enteredUsername) == 0 && strcmp(buftoken[i + 1], enteredPassword) == 0) 
	    {
			printf("Login successful.\n");
			userlogin(buftoken[i]);
			validCredentials = 1;
		
		break; // Break the loop if valid credentials are found
	    }
	    
	}

	if (validCredentials) 
	{
		break; // Break the outer loop if valid credentials are found
	} 
	else 
	{
		printf("Login failed. Invalid username or password. Try again.\n");
	}
	}
	
	// Free memory for buftoken
	for (int j = 0; j < sizeof(buftoken)-1 ; ++j) 
	{
		free(buftoken[j]);
	}
	free(buftoken);

	// Free allocated memory
	free(user1.username);
	free(user1.password);

	close(fd); // Close the file descriptor
	return;
}

