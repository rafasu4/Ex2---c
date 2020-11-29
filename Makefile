CC = gcc
AR = ar
mymaths = libmyMath.a
FLAGS = -Wall -g

all: mains

#static exe
mains: myBank.o main.o mymaths
	$(CC) $(FLAGS) -o mains main.o myBank.o mymaths
	
#creating static library
mymaths: myBank.o
	$(AR) -rcs mymaths myBank.o	 	


main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c
		
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c



.PHONY: clean all

clean:
	rm -f *.o *.so *.a mains mymaths		
