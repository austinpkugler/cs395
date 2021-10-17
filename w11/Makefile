CC = gcc
CFLAGS = -Wall

all: a.out
clean:
	rm -rf a.out *.o

a.out: w11.c
	$(CC) $(CFLAGS) w11.c -o a.out
w01.o: w11.c
	$(CC) $(CFLAGS) -c w11.c