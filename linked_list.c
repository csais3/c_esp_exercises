#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void print_linked_list(Node *root);

int main() {

    Node nodeRoot = {10, NULL};
    Node element1 = {5, NULL};
    nodeRoot.next = &element1;

    //printf("Element 1 value: %d\n", nodeRoot.value);
    //printf("Element 2 value: %d\n", nodeRoot.next->value);
    print_linked_list(&nodeRoot);
}

void traverse_linked_list(Node *node) {
    Node *current = node;
    while (current != NULL) {
        printf("Current value: %d\n", current->value);
        current = current->next;
    }
}

void print_linked_list(Node *root) {
    
}