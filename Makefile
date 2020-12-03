CC = gcc
AR = ar
mybanks = libmyBank.a
FLAGS = -Wall -g

all: mains

#static exe
mains: myBank.o main.o mybanks
	$(CC) $(FLAGS) -o mains main.o myBank.o mybanks
	
#creating static library
mybanks: myBank.o
	$(AR) -rcs mybanks myBank.o	 	


main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c
		
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c



.PHONY: clean all

clean:
	rm -f *.o *.so *.a mains mybanks		
