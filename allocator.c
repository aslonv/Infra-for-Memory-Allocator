#include "allocator.h"
#include <stdio.h>
#include <string.h>

typedef struct Block {
    size_t size;
    int is_free;
    struct Block *next;
} Block;

static char memory[MEMORY_SIZE];
static Block *head = (Block *)memory;

void init_allocator() {
    head->size = MEMORY_SIZE - sizeof(Block);
    head->is_free = 1;
    head->next = NULL;
}

void *my_malloc(size_t size) {
    Block *current = head;
    while (current) {
        if (current->is_free && current->size >= size + sizeof(Block)) {
            if (current->size > size + sizeof(Block) + BLOCK_SIZE) {
                Block *new_block = (Block *)((char *)current + sizeof(Block) + size);
                new_block->size = current->size - size - sizeof(Block);
                new_block->is_free = 1;
                new_block->next = current->next;
                
                current->size = size;
                current->is_free = 0;
                current->next = new_block;
            } else {
                current->is_free = 0;
            }
            return (void *)((char *)current + sizeof(Block));
        }
        current = current->next;
    }
    return NULL;
}

void my_free(void *ptr) {
    if (!ptr) return;
    
    Block *block = (Block *)((char *)ptr - sizeof(Block));
    block->is_free = 1;
    
    // Merge with next block if it's free
    if (block->next && block->next->is_free) {
        block->size += block->next->size + sizeof(Block);
        block->next = block->next->next;
    }
}

void print_memory_layout() {
    Block *current = head;
    int i = 0;
    while (current) {
        printf("Block %d: Address: %p, Size: %zu, Is Free: %d\n", 
               i++, (void *)current, current->size, current->is_free);
        current = current->next;
    }
    printf("\n");
}