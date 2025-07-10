#include <stdio.h>
#include <stdlib.h>

int get_random_value() {
    int value;  // Uninitialized
    return value;
}

int main() {
    // Example 1: Uninitialized local variable
    int x;
    printf("Uninitialized int x: %d\n", x);
    
    // Example 2: Uninitialized pointer
    int* ptr;
    printf("Uninitialized pointer value: %p\n", (void*)ptr);
    // Uncommenting the next line would likely crash
    // printf("Dereferencing uninitialized pointer: %d\n", *ptr);
    
    // Example 3: Uninitialized array
    int array[10];
    printf("\nUninitialized array values:\n");
    for (int i = 0; i < 10; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    
    // Example 4: Using uninitialized value in calculation
    int a;
    int b = 10;
    int result = a + b;
    printf("\nCalculation with uninitialized value:\n");
    printf("a (uninitialized) + b (10) = %d\n", result);
    
    // Example 5: Function returning uninitialized value
    int random = get_random_value();
    printf("\nValue from function: %d\n", random);
    
    // Example 6: Conditional based on uninitialized value
    int flag;
    if (flag) {
        printf("\nFlag was true (non-zero)\n");
    } else {
        printf("\nFlag was false (zero)\n");
    }
    
    return 0;
}