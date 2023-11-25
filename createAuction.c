#include "header.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

struct AuctionItem Auctionlist[10];
static int count = 0;
// Function to create a new auction
void* printTimeAndRemaining(void* arg) {
    Auctionth* auction = (Auctionth*)arg;

    while (1) {
        pthread_mutex_lock(&mutex);

        puts("******************************#");
        printf("Time remaining: %ld seconds\n", auction->deadline - time(NULL));
        puts("******************************#");

        pthread_mutex_unlock(&mutex);

        sleep(1);

        if (time(NULL) > auction->deadline) {
            pthread_mutex_lock(&mutex);

            auction->is_valid = 0;
            printf("%s item is invalid!\n", Auctionlist[count].item_name);

            // Delete the expired auction item and adjust count
            for (int i = 0; i < count - 1; i++) {
                Auctionlist[i] = Auctionlist[i + 1];
            }

            // Reset the last item
            memset(&Auctionlist[count - 1], 0, sizeof(struct AuctionItem));
            count--;

            pthread_mutex_unlock(&mutex);
		//userlogin(auction->username);
           // input();
            
            return NULL;
        }

        userlogin(auction->username);
    }

    return NULL;
}


void createNewAuction(char* username) 
{


	int fd = open("data.txt", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);

	if (fd == -1) 
	{
		perror("Failed to open file Auction\n");
		exit(EXIT_FAILURE);
	}

	strncpy(Auctionlist[count].user_name, username, strlen(username));



	printf("Enter the name of the item: ");
	if (scanf("%s", Auctionlist[count].item_name) != 1) 
	{
		perror("Error reading item name\n");
		exit(EXIT_FAILURE);
	}


	if (dprintf(fd, "%s %s ", username, Auctionlist[count].item_name) < 0) 
	{
		perror("dprintf");
		exit(EXIT_FAILURE);
	}


	printf("Enter the starting price: ");
	if (scanf("%f", &Auctionlist[count].starting_price) != 1) 
	{
		perror("Error reading starting price\n");
		exit(EXIT_FAILURE);
	}


	if (dprintf(fd, "%.2f ", Auctionlist[count].starting_price) < 0) 
	{
		perror("dprintf");
		exit(EXIT_FAILURE);
	}
	if (dprintf(fd, "%s ", "\n") < 0) 
	{
		perror("dprintf");
		exit(EXIT_FAILURE);
	}
	count++;
	printf("Count : %d\n",count);
	Auctionth auction [10];
	strcpy(auction[count].username, username);
	auction[count].start_time = time(NULL);
	auction[count].deadline = auction[count].start_time+60;
	auction[count].is_valid = 1;
	
	pthread_t timeThread[10];
	pthread_create(&timeThread[count], NULL, printTimeAndRemaining,(void*)&auction[count]);

	
	
	
	pthread_join(timeThread[count],NULL);
	
	performBidDeadlineActions(&Auctionlist[count], username);

	close(fd);
}


