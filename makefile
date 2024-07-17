CC = gcc
CFLAGS = -Wall -Wextra -g

all: allocator

allocator: allocator.c main.c
	$(CC) $(CFLAGS) -o allocator allocator.c main.c

clean:
	rm -f allocator

test: allocator.c test_allocator.c
	$(CC) $(CFLAGS) -o test_allocator allocator.c test_allocator.c
	./test_allocator