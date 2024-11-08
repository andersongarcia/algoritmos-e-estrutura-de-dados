CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = hash-linear

all: $(TARGET)

$(TARGET): hash-linear.o
	$(CC) $(CFLAGS) -o $(TARGET) hash-linear.o

hash-linear.o: hash-linear.c
	$(CC) $(CFLAGS) -c hash-linear.c

clean:
	rm -f *.o $(TARGET)

.PHONY: all clean
