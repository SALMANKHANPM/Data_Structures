#include <stdio.h>
#include <stdlib.h>

// Define a node of the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    if (*headRef != NULL) {
        (*headRef)->prev = newNode;
    }
    *headRef = newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    struct Node* lastNode = *headRef;
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->prev = lastNode;
}

// Function to delete the first occurrence of a node with the given data
void deleteNode(struct Node** headRef, int data) {
    struct Node* currentNode = *headRef;
    while (currentNode != NULL) {
        if (currentNode->data == data) {
            if (currentNode->prev != NULL) {
                currentNode->prev->next = currentNode->next;
            } else {
                *headRef = currentNode->next;
            }
            if (currentNode->next != NULL) {
                currentNode->next->prev = currentNode->prev;
            }
            free(currentNode);
            return;
        }
        currentNode = currentNode->next;
    }
}

// Function to display the list
void displayList(struct Node* head) {
    struct Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Delete node");
        printf("\n4. Display list");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
