#include <stdio.h>
#include <limits.h>

int main() {
    // Example 1: Basic integer overflow
    int a = INT_MAX;
    int b = 1;
    int result = a + b;
    
    printf("INT_MAX: %d\n", INT_MAX);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("a + b = %d\n", result);
    
    // Example 2: Multiplication overflow
    int x = 1000000;
    int y = 1000000;
    int product = x * y;
    
    printf("\nMultiplication overflow:\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("x * y = %d\n", product);
    
    // Example 3: Array index overflow
    int arr[10];
    int index = 15;  // Out of bounds
    
    printf("\nArray access (index %d):\n", index);
    arr[index] = 42;  // This might cause undefined behavior
    printf("arr[%d] = %d\n", index, arr[index]);
    
    return 0;
}