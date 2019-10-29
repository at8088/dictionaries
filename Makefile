CC=gcc
CFLAGS=-g -Wall -O -std=c99
test1: bin/test1.o bin/fct-primitives.o
	$(CC) -o bin/$@ $^
bin/%.o:src/%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f bin/*
