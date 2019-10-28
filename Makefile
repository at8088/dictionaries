CC=gcc
CFLAGS=-g -Wall -O
test1: bin/test_create_destroy.o bin/fct-primitives.o
	$(CC) -o $@ $^
bin/%.o:src/%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(BINDIR)/*
