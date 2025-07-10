#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Example 1: Basic use after free
    int* ptr = (int*)malloc(sizeof(int));
    *ptr = 42;
    printf("Value before free: %d\n", *ptr);
    
    free(ptr);
    
    printf("Attempting to use after free...\n");
    printf("Value after free: %d\n", *ptr);  // Use after free
    *ptr = 100;  // Write after free
    
    // Example 2: Double free
    int* another_ptr = (int*)malloc(sizeof(int));
    *another_ptr = 123;
    free(another_ptr);
    free(another_ptr);  // Double free - undefined behavior
    
    // Example 3: Use after free with strings
    char* buffer = (char*)malloc(20);
    strcpy(buffer, "Hello, World!");
    printf("\nString before free: %s\n", buffer);
    
    free(buffer);
    
    printf("String after free: %s\n", buffer);  // Use after free
    strcpy(buffer, "Oops!");  // Write after free
    
    return 0;
}