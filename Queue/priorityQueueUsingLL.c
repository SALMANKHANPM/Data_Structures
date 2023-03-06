#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* front = NULL;

int is_empty() {
    return front == NULL;
}

void enqueue(int x, int priority) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->priority = priority;
    temp->next = NULL;
    if (is_empty() || priority < front->priority) {
        temp->next = front;
        front = temp;
    }
    else {
        struct Node* current = front;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
    printf("Element added: %d\n", x);
}

void dequeue() {
    if (is_empty()) {
        printf("Queue is empty.\n");
    }
    else {
        struct Node* temp = front;
        printf("Element removed: %d\n", temp->data);
        front = front->next;
        free(temp);
    }
}

void display() {
    if (is_empty()) {
        printf("Queue is empty.\n");
    }
    else {
        struct Node* current = front;
        printf("Queue elements: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, x, priority;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &x);
                printf("Enter the priority of the element: ");
                scanf("%d", &priority);
                enqueue(x, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
