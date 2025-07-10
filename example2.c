#include <stdio.h>
#include <string.h>

int main() {
    // Example 1: Wrong format specifier
    int number = 42;
    printf("Number as string: %s\n", number);  // Wrong: %s expects char*, not int
    
    // Example 2: Implicit narrowing conversion
    int large_number = 300;
    char small_char = large_number;  // Narrowing conversion
    printf("\nNarrowing conversion:\n");
    printf("Original int: %d\n", large_number);
    printf("After conversion to char: %d\n", small_char);
    
    // Example 3: Pointer type confusion
    int integer = 12345;
    float* float_ptr = (float*)&integer;
    printf("\nPointer type confusion:\n");
    printf("Integer value: %d\n", integer);
    printf("Same bytes interpreted as float: %f\n", *float_ptr);
    
    // Example 4: Format string mismatch with multiple arguments
    double pi = 3.14159;
    printf("\nFormat string mismatch:\n");
    printf("Pi value: %d\n", pi);  // Wrong: %d expects int, not double
    
    // Example 5: String/pointer confusion
    char* message = "Hello";
    printf("\nString as number: %d\n", message);  // Printing pointer as int
    
    return 0;
}