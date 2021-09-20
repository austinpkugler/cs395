CC = gcc
CFLAGS = -Wall

all: a.out
clean:
	rm -rf a.out *.o

a.out: w04.c
	$(CC) $(CFLAGS) w04.c -o a.out
w01.o: w04.c
	$(CC) $(CFLAGS) -c w04.c