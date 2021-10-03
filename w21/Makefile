CC = gcc
CFLAGS = -Wall

all: a.out
clean:
	rm -rf a.out *.o

a.out: w21.c
	$(CC) $(CFLAGS) w21.c -o a.out
w01.o: w21.c
	$(CC) $(CFLAGS) -c w21.c