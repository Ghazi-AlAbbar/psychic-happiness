#include "header.h"

void registerUser(char *username, char *password) {
  
  

    int fd = open("Usernamelist.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);

    if (fd == -1) {
        perror("Failed to open file\n");
        exit(EXIT_FAILURE);
    }

    

    char** buftoken = parse_cmd(fd);

    // Prompt the user to enter credentials
    char enteredUsername[MAX_USERNAME];
    char enteredPassword[MAX_PASSWORD];
    int validCredentials = 0;

    do {
        printf("Enter username (max %d characters): ", MAX_USERNAME - 1);

        if (scanf("%s", enteredUsername) != 1) {
            perror("Error reading username\n");
            exit(EXIT_FAILURE);
        }

        

        // Check if the entered username already exists
        validCredentials = 1;
        for (int i = 0; buftoken[i] != NULL; i += 2) {
            if (strcmp(buftoken[i], enteredUsername) == 0) {
                validCredentials = 0;
                printf("Username '%s' already exists. Please choose a different username.\n", enteredUsername);
                break;
            }
        }

    } while (!validCredentials);
	printf("Enter password (max %d characters): ", MAX_PASSWORD - 1);

        if (scanf("%s", enteredPassword) != 1) {
            perror("Error reading password\n");
            exit(EXIT_FAILURE);
        }
    // Write the new user information to the file
    if (write(fd, enteredUsername, strlen(enteredUsername)) != strlen(enteredUsername)) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Add a space after the username
    if (write(fd, " ", 1) != 1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    if (write(fd, enteredPassword, strlen(enteredPassword)) != strlen(enteredPassword)) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Add a newline after the password
    if (write(fd, "\n", 1) != 1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    printf("User registered successfully.\n");

    close(fd);
}

