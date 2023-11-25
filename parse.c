#include "header.h"

char** parse_cmd(int fd) {
	struct stat statfd; // Declare a variable to hold file stat information.
	if (fstat(fd, &statfd) == -1) 
	{
		perror("Failed state\n");
		exit(EXIT_FAILURE);
	}

	int sizefd = statfd.st_size;
	char* strbuf = (char*)malloc(sizefd * sizeof(char));

	if (strbuf == NULL) 
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	read(fd, strbuf, sizefd);

	// Null-terminate the string and remove newline characters
	for (int i = 0; i < sizefd; i++) 
	{
		if (strbuf[i] == '\n') {
			strbuf[i] = ' ';
		}
	}
	strbuf[sizefd - 1] = '\0';

	char** buftoken = (char**)malloc(sizefd * sizeof(char*));

	if (buftoken == NULL) 
	{
		fprintf(stderr, "Memory allocation failed\n");
		free(strbuf);
		exit(EXIT_FAILURE);
	}

	char* token;
	int i = 0;

	token = strtok(strbuf, " ");
	while (token != NULL) 
	{
		buftoken[i] = strdup(token);
		if (buftoken[i] == NULL) 
		{
			fprintf(stderr, "Memory allocation failed\n");
			for (int j = 0; j < i; ++j) 
			{
				free(buftoken[j]);
			}
			free(buftoken);
			free(strbuf);
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, " ");
	}

	free(strbuf);
	for(int i=0; buftoken[i]!='\0'; i++)
	{
		
		printf("%d:  %s\n ",i,buftoken[i]);
		
	}
	puts(" ");
	return buftoken;
}

	

