CC = gcc
CFLAGS = -Wall

all: a.out
clean:
	rm -rf a.out *.o

a.out: w01.o
	$(CC) $(CFLAGS) w01.o -o a.out
w01.o: w01.c
	$(CC) $(CFLAGS) -c w01.c