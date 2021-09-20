CC = gcc
CFLAGS = -Wall

all: a.out
clean:
	rm -rf a.out *.o

a.out: w05.c
	$(CC) $(CFLAGS) w05.c -o a.out
w01.o: w05.c
	$(CC) $(CFLAGS) -c w05.c