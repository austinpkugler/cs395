CC = gcc
CFLAGS = -Wall

all: a.out
clean:
	rm -rf a.out *.o

a.out: w07.c
	$(CC) $(CFLAGS) w07.c -o a.out
w01.o: w07.c
	$(CC) $(CFLAGS) -c w07.c