


all: mains

#static exe
mains: myBank.o main.o myBanks
	gcc -Wall -g -o mains main.o myBank.o myBanks

#creating static library
myBanks: myBank.o
	ar - rcs myBanks myBank.o

myBank.o: myBank.c myBank.h
	gcc -Wall -g -c myBank.o
main.o: main.c myBank.h
	gcc -Wall -g -c main.c  
	
.PHONY: all clean

clean:
	rm -f *.o *so *.a myBanks	
