#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <pthread.h>
#define MAX_USERNAME 10
#define MAX_PASSWORD 9
struct User {
    char *username;
    char *password;
};


#ifndef AUCTION_H
#define AUCTION_H
#include <pthread.h>
#include <time.h>
struct AuctionItem {
    char user_name[5];
    char item_name[50];
    float starting_price;
    
    
};
typedef struct Auctionthread
{
	time_t remining_time;
	time_t start_time;
	time_t deadline;
    	int is_valid;
    	char username[5];
} Auctionth;
void createNewAuction(char *);




extern struct AuctionItem Auctionlist[10];

extern pthread_mutex_t mutex;

#endif



char** parse_cmd(int);
void registerUser(char*,char*);
void createNewAuction(char*);
void login();
void input();
void printActiveAuctions(char* );
void userlogin(char*);
void updatingfd(char *,int);
void real_time(time_t);
void Bidding( char*,int);
void* printTimeAndRemaining(void* );
void performBidDeadlineActions(const struct AuctionItem*,char*);

