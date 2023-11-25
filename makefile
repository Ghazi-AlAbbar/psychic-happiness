# Mohamed El-Assar
all:
	make objects lib223 cs223

objects:
	
	gcc -c bidding.c -o bidding.o -pthread -lm
	gcc -c login.c -o login.o
	gcc -c createAuction.c -o createAuction.o
	gcc -c Auction_regi.c -o Auction_regi.o -pthread -lm
	gcc -c parse.c -o parse.o

lib223: objects
	ar rs lib223.a bidding.o login.o createAuction.o Auction_regi.o parse.o

cs223: objects lib223
	gcc input.c lib223.a -o cs223

clean:
	rm -f *.o lib223.a cs223
