#ifndef ALLOCATOR_H
#define ALLOCATOR_h

#include <stddef.h>

#define MEMORY_SIZE 1024
#define BLOCK_SIZE 16

void init_allocator();
void *my_malloc(size_t size);
void my_free(void *ptr);
void print_memory_layout();

#endif // ALLOCATOR_h