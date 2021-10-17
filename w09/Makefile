CC = gcc
CFLAGS = -Wall

all: a.out
clean:
	rm -rf a.out *.o

a.out: w09.c
	$(CC) $(CFLAGS) w09.c -o a.out
w01.o: w09.c
	$(CC) $(CFLAGS) -c w09.c