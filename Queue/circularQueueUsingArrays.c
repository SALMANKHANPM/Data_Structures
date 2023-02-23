#include <stdio.h>
#define MAX_SIZE 5

int front = -1, rear = -1;
int queue[MAX_SIZE];

int is_empty() {
    return front == -1 && rear == -1;
}

int is_full() {
    return (rear + 1) % MAX_SIZE == front;
}

void enqueue(int x) {
    int choice;
    if (is_full()) {
        printf("Queue is full.\n");
    }
    else {
        if (is_empty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % MAX_SIZE;
        }
        queue[rear] = x;
        printf("Element added: %d\n", x);
    }
}

void dequeue() {
    int choice;
    if (is_empty()) {
        printf("Queue is empty.\n");
    }
    else {
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX_SIZE;
        }
    }
}

void display() {
    int choice;
    if (is_empty()) {
        printf("Queue is empty.\n");
    }
    else {
        int i = front;
        printf("Queue elements: ");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", queue[i]);
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
