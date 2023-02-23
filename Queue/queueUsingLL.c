#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) { // if queue is empty
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    if (front == NULL) { // if queue is empty
        printf("Queue underflow!\n");
        return -1;
    }
    int value = front->data;
    Node* temp = front;
    front = front->next;
    free(temp);

    if (front == NULL) { // if only one element was in the queue
        rear = NULL;
    }
    return value;
}

int peek() {
    if (front == NULL) { // if queue is empty
        printf("Queue is empty!\n");
        return -1;
    }
    return front->data;
}

void display() {
    if (front == NULL) { // if queue is empty
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are: ");
    Node* current = front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) { // keep the program running until the user chooses to exit
        printf("\nQueue Implementation using Linked List in C\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                value = dequeue();
                if (value != -1) { // check if dequeue was successful
                    printf("Dequeued value is %d\n", value);
                }
                break;

            case 3:
                value = peek();
                if (value != -1) { // check if peek was successful
                    printf("Front value is %d\n", value);
                }
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0); // exit the program

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
