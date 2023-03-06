#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

int is_empty() {
    return front == NULL && rear == NULL;
}

void enqueue(int x) {
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = x;
    if (is_empty()) {
        front = rear = new_node;
    }
    else {
        rear->next = new_node;
        rear = new_node;
    }
    rear->next = front;
    printf("Element added: %d\n", x);
}

void dequeue() {
    if (is_empty()) {
        printf("Queue is empty.\n");
    }
    else {
        struct Node *temp = front;
        printf("Element removed: %d\n", front->data);
        if (front == rear) {
            front = rear = NULL;
        }
        else {
            front = front->next;
            rear->next = front;
        }
        free(temp);
    }
}

void display() {
    if (is_empty()) {
        printf("Queue is empty.\n");
    }
    else {
        struct Node *temp = front;
        printf("Queue elements: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != front);
        printf("\n");
    }
}

int main() {
    int choice, x;
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
                enqueue(x);
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
