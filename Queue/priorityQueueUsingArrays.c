#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int front = -1, rear = -1;
int queue[MAX];

int is_empty() {
    return front == -1 && rear == -1;
}

int is_full() {
    return rear == MAX - 1;
}

void enqueue(int x) {
    if (is_full()) {
        printf("Queue is full.\n");
    }
    else if (is_empty()) {
        front = rear = 0;
        queue[rear] = x;
    }
    else {
        int i, j;
        for (i = front; i <= rear; i++) {
            if (x > queue[i]) {
                for (j = rear + 1; j > i; j--) {
                    queue[j] = queue[j - 1];
                }
                queue[i] = x;
                rear++;
                return;
            }
        }
        queue[++rear] = x;
    }
    printf("Element added: %d\n", x);
}

void dequeue() {
    if (is_empty()) {
        printf("Queue is empty.\n");
    }
    else if (front == rear) {
        printf("Element removed: %d\n", queue[front]);
        front = rear = -1;
    }
    else {
        printf("Element removed: %d\n", queue[front++]);
    }
}

void display() {
    if (is_empty()) {
        printf("Queue is empty.\n");
    }
    else {
        int i;
        printf("Queue elements: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
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
