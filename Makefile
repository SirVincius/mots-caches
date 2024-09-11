CC=gcc
OPTIONS= -std=c11 -g -Wall

link: compile
	$(CC) $(OPTIONS) -o motscaches motscaches.o

compile:
	$(CC) $(OPTIONS) -c motscaches.c

test: link
	bats tests.bats

clean:
	rm -rf motscaches motscaches.o


