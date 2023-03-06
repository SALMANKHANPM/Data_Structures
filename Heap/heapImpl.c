#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Heap {
    struct Node* root;
};

void insert(struct Heap* heap, int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    if (heap->root == NULL) {
        heap->root = newNode;
        return;
    }
    struct Node* parent = NULL;
    struct Node* current = heap->root;
    while (current != NULL) {
        parent = current;
        if (value > current->value) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
    if (value > parent->value) {
        parent->right = newNode;
    } else {
        parent->left = newNode;
    }
}

int removeMax(struct Heap* heap) {
    if (heap->root == NULL) {
        printf("Heap is empty\n");
        return -1;
    }
    int max = heap->root->value;
    struct Node* parent = NULL;
    struct Node* current = heap->root;
    while (current->right != NULL) {
        parent = current;
        current = current->right;
    }
    if (current->left != NULL) {
        parent->right = current->left;
    } else {
        parent->right = NULL;
    }
    free(current);
    return max;
}

int main() {
    struct Heap heap;
    heap.root = NULL;
    int choice = 0;
    while (choice != 3) {
        printf("Please choose an option:\n");
        printf("1. Add a value to the heap\n");
        printf("2. Remove the maximum value from the heap\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                int value;
                scanf("%d", &value);
                insert(&heap, value);
                break;
            case 2:
                printf("Removed max value: %d\n", removeMax(&heap));
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
