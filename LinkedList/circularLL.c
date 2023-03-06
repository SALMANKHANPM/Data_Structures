#include <stdio.h>
#include <stdlib.h>

// Define a node of the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        newNode->next = newNode;
        *headRef = newNode;
        return;
    }
    struct Node* lastNode = (*headRef)->next;
    while (lastNode->next != (*headRef)->next) {
        lastNode = lastNode->next;
    }
    newNode->next = *headRef;
    lastNode->next = newNode;
    *headRef = newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        newNode->next = newNode;
        *headRef = newNode;
        return;
    }
    struct Node* lastNode = (*headRef)->next;
    while (lastNode->next != (*headRef)->next) {
        lastNode = lastNode->next;
    }
    newNode->next = (*headRef)->next;
    (*headRef)->next = newNode;
    *headRef = newNode;
    lastNode->next = *headRef;
}

// Function to delete the first occurrence of a node with the given data
void deleteNode(struct Node** headRef, int data) {
    if (*headRef == NULL) {
        return;
    }
    struct Node* currentNode = *headRef;
    if (currentNode->data == data) {
        if (currentNode->next == *headRef) {
            free(currentNode);
            *headRef = NULL;
            return;
        }
        struct Node* lastNode = *headRef;
        while (lastNode->next != *headRef) {
            lastNode = lastNode->next;
        }
        lastNode->next = (*headRef)->next;
        *headRef = (*headRef)->next;
        free(currentNode);
        return;
    }
    struct Node* prevNode = *headRef;
    while (currentNode->data != data) {
        if (currentNode->next == *headRef) {
            printf("%d not found in the list\n", data);
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    prevNode->next = currentNode->next;
    free(currentNode);
}

// Function to display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        return;
    }
    struct Node* currentNode = head->next;
    printf("%d ", head->data);
    while (currentNode != head) {
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
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter the data: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}