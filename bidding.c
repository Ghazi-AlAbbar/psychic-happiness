#include "header.h"


float current_price;
int count;


void updatingfd(char *username,int i) 
{
	int fd = open("data.txt", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);

	if (fd == -1) 
	{
		perror("Failed to open file Auction\n");
		exit(EXIT_FAILURE);
	}
	strncpy(Auctionlist[i].user_name, username, strlen(username));


	if (dprintf(fd, "%s %s %.2f ",Auctionlist[i].user_name, Auctionlist[i].item_name, Auctionlist[i].starting_price) < 0) 
	{
		perror("dprintf");
		exit(EXIT_FAILURE);
	}
	if (dprintf(fd, "%s ", "\n") < 0) 
	{
		perror("dprintf");
		exit(EXIT_FAILURE);
	}

	close(fd);
}

void Bidding(char* username, int count1) 
{
	
	count=count1;
	float bid_amount;
	char item_name[50];
	int visited =0;
	int i=0;
	Auctionth *auction = &auction[10]; 
	for(int c=0; c<count; c++)
	{
		printf("the name of the item: %s\n",Auctionlist[c].item_name);

		printf("the starting price: %.3f\n",Auctionlist[c].starting_price);
	}
	printf(" username %s\n",(char*)&auction->username);
	printf("Enter the name of the item you want to bid on: ");
	scanf("%s", item_name);
	for( ; i < count; i++)
	{
	

		if (strcmp(Auctionlist[i].item_name, item_name) == 0)
		{	if (strcmp(Auctionlist[i].user_name, username) == 0){
                
               			 printf("You cannot bid on your own item!\n");
               			 break;
           		 }
			current_price = Auctionlist[i].starting_price;
			visited=1;
			break;
		}

	}

	if(visited == 1)
	{

		puts("\t\tWelcome to the Auction Platform!");
		printf("Get ready to bid on the item '%s'. The starting price is %.2f KD.\n", Auctionlist[i].item_name,  Auctionlist[i].starting_price);
	
		printf("Enter your bid amount: ");

		if (scanf("%f", &bid_amount) != 1) 
		{
			perror("Error reading bid amount\n");
			exit(EXIT_FAILURE);
		}
		
		if (bid_amount > Auctionlist[i].starting_price) 
		{
			Auctionlist[i].starting_price=bid_amount;
			updatingfd(username,i);
			puts("==============================================");
			printf("Current price for item '%s': %.2f KD.\n", Auctionlist[i].item_name,current_price);
			puts("----------------------------------------------");
			printf("%s raised the bid for '%s' to: %.2f KD.\n", Auctionlist[i].user_name, Auctionlist[i].item_name,Auctionlist[i].starting_price);
			puts("----------------------------------------------");
			printf("The new price for item '%s' is: %.2f KD.\n", Auctionlist[i].item_name, Auctionlist[i].starting_price);
			puts("==============================================");
			
			//userlogin(username);
			
		} 
		
		
		else if (bid_amount < Auctionlist[i].starting_price) 
		{
			printf("Bid amount must be higher than the current price. Bid rejected.\n");
		}
		
		
	
	}
	else 
	{
	
		printf("Item '%s' not found in the auction.\n",Auctionlist[i].item_name);
	}

}

void performBidDeadlineActions(const struct AuctionItem* item, char* buftoken) 
{

	int count=0;
	printf("The final price for '%s' is: %.2f KD.\n", Auctionlist[count].item_name, current_price);
	puts("\t\t-----------------------------------------------------------------\n");
	printf("Congratulations! You are the winner of the auction for item '%s'.\n", Auctionlist[count].item_name);
	puts("\t\t-----------------------------------------------------------------\n");
	printf("Thank you for participating. Bidding for '%s' has ended.\n", Auctionlist[count].item_name);
	userlogin(buftoken);

    
}


