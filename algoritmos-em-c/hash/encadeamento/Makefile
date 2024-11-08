CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: hash_int hash_string

hash_int: main_int.o hash-lista-int.o
	$(CC) $(CFLAGS) -o hash_int main_int.o hash-lista-int.o

hash_string: main_string.o hash-lista-string.o
	$(CC) $(CFLAGS) -o hash_string main_string.o hash-lista-string.o

main_int.o: main_int.c hash.h
	$(CC) $(CFLAGS) -c main_int.c

hash-lista-int.o: hash-lista-int.c hash.h
	$(CC) $(CFLAGS) -c hash-lista-int.c

main_string.o: main_string.c hash.h
	$(CC) $(CFLAGS) -c main_string.c

hash-lista-string.o: hash-lista-string.c hash.h
	$(CC) $(CFLAGS) -c hash-lista-string.c

clean:
	rm -f *.o hash_int hash_string

.PHONY: all clean