#include <stdio.h>
#include <stdlib.h>

void process_data(int* data) {
    printf("Processing value: %d\n", *data);
}

int main() {
    // Example 1: Basic null pointer dereference
    int* ptr = NULL;
    printf("Attempting to dereference NULL pointer...\n");
    printf("Value: %d\n", *ptr);  // This will crash
    
    // Example 2: Function call with NULL
    process_data(NULL);
    
    // Example 3: Array access through NULL
    int* array = NULL;
    array[5] = 42;
    
    // Example 4: Struct member access through NULL
    struct Point {
        int x;
        int y;
    };
    struct Point* point = NULL;
    point->x = 10;  // NULL pointer dereference
    
    return 0;
}