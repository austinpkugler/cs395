CC = gcc
CFLAGS = -Wall

all: a.out
clean:
	rm -rf a.out *.o

a.out: w06.c
	$(CC) $(CFLAGS) w06.c -o a.out
w01.o: w06.c
	$(CC) $(CFLAGS) -c w06.c