#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Complex use-after-free scenarios that might evade simple detection

struct Node {
    int data;
    struct Node* next;
};

// Function that frees memory through a pointer parameter
void cleanup_node(struct Node** node) {
    free(*node);
    // *node = NULL;  // Good practice, but commented out to test detection
}

// Function that returns a freed pointer
struct Node* get_freed_node() {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = 999;
    free(temp);
    return temp;  // Returning freed memory
}

int main() {
    // Example 1: Use after free through aliasing
    printf("=== Example 1: Aliasing ===\n");
    int* original = malloc(sizeof(int));
    *original = 42;
    int* alias = original;  // Create an alias
    
    free(original);
    
    printf("Using alias after original was freed: %d\n", *alias);  // Use after free via alias
    *alias = 100;  // Write after free via alias
    
    // Example 2: Use after free through function parameter
    printf("\n=== Example 2: Function Parameter ===\n");
    struct Node* node = malloc(sizeof(struct Node));
    node->data = 123;
    struct Node* node_backup = node;  // Keep a copy
    
    cleanup_node(&node);
    
    printf("Accessing freed node: %d\n", node_backup->data);  // Use after free
    
    // Example 3: Use after free with function return
    printf("\n=== Example 3: Function Return ===\n");
    struct Node* freed_node = get_freed_node();
    printf("Accessing returned freed memory: %d\n", freed_node->data);  // Use after free
    
    // Example 4: Use after free in a loop
    printf("\n=== Example 4: Loop Scenario ===\n");
    struct Node* list = NULL;
    struct Node* current = NULL;
    
    // Create a small linked list
    for (int i = 0; i < 3; i++) {
        struct Node* new_node = malloc(sizeof(struct Node));
        new_node->data = i;
        new_node->next = list;
        list = new_node;
    }
    
    // Free all nodes but keep using them
    current = list;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        printf("Freed node had data: %d\n", current->data);  // Use after free
        current = next;
    }
    
    // Example 5: Conditional use after free
    printf("\n=== Example 5: Conditional ===\n");
    int* ptr = malloc(sizeof(int));
    *ptr = 777;
    int should_free = 1;
    
    if (should_free) {
        free(ptr);
    }
    
    // Later in code, forgetting the conditional free
    printf("Value: %d\n", *ptr);  // Use after free (conditional)
    
    return 0;
}