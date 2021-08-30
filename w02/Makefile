CC = gcc
CFLAGS = -Wall

all: a.out
clean:
	rm -rf a.out *.o

a.out: w02.o
	$(CC) $(CFLAGS) w02.o -o a.out
w01.o: w02.c
	$(CC) $(CFLAGS) -c w02.c