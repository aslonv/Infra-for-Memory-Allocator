#include "allocator.h"
#include <assert.h>
#include <stdio.h>

void test_allocation() {
    init_allocator();

    int *a = (int *)my_malloc(sizeof(int) * 5);
    assert(a != NULL);

    char *b = (char *)my_malloc(sizeof(char) * 10);
    assert(b != NULL);

    double *c = (double *)my_malloc(sizeof(double) * 3);
    assert(c != NULL);

    my_free(a);
    my_free(b);
    my_free(c);

    printf("Allocation test passed!\n");
}

int main() {
    test_allocation();
    return 0;
}