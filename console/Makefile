CC = gcc
CFLAGS = -Wall

all: main

main: main.o hello.o
	$(CC) $(CFLAGS) -o main main.o hello.o

main.o: main.c hello.h
	$(CC) $(CFLAGS) -c main.c

hello.o: hello.c hello.h
	$(CC) $(CFLAGS) -c hello.c

clean:
	rm -f *.o