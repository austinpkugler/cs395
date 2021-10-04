CC = gcc
CFLAGS = -Wall

all: a.out
clean:
	rm -rf a.out *.o

a.out: w08.c
	$(CC) $(CFLAGS) w08.c -o a.out
w01.o: w08.c
	$(CC) $(CFLAGS) -c w08.c