CC = gcc
CFLAGS = -Wall

all: a.out
clean:
	rm -rf a.out *.o

a.out: w03.c
	$(CC) $(CFLAGS) w03.c -o a.out
w01.o: w03.c
	$(CC) $(CFLAGS) -c w03.c