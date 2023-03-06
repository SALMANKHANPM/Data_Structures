#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert_beginning(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
    printf("Element inserted at beginning: %d\n", x);
}

void insert_end(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    }
    else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
    printf("Element inserted at end: %d\n", x);
}

void delete_beginning() {
    if (head == NULL) {
        printf("List is empty.\n");
    }
    else {
        struct Node* temp = head;
        head = head->next;
        printf("Element deleted from beginning: %d\n", temp->data);
        free(temp);
    }
}

void delete_end() {
    if (head == NULL) {
        printf("List is empty.\n");
    }
    else if (head->next == NULL) {
        struct Node* temp = head;
        head = NULL;
        printf("Element deleted from end: %d\n", temp->data);
        free(temp);
    }
    else {
        struct Node* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        struct Node* temp = current->next;
        current->next = NULL;
        printf("Element deleted from end: %d\n", temp->data);
        free(temp);
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
    }
    else {
        struct Node* current = head;
        printf("List elements: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, x;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &x);
                insert_beginning(x);
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &x);
                insert_end(x);
                break;
            case 3:
                delete_beginning();
                break;
            case 4:
                delete_end();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
