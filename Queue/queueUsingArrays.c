#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1; // initialize front and rear pointers to -1

void enqueue(int value) {
    if (rear == MAX_SIZE - 1) { // check if queue is full
        printf("Queue overflow!\n");
        return;
    }
    if (front == -1) { // check if queue is empty
        front = 0;
    }
    rear++;
    queue[rear] = value;
}

int dequeue() {
    if (front == -1) { // check if queue is empty
        printf("Queue underflow!\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear) { // if there's only one element
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    return value;
}

int peek() {
    if (front == -1) { // check if queue is empty
        printf("Queue is empty!\n");
        return -1;
    }
    return queue[front];
}

void display() {
    if (front == -1) { // check if queue is empty
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) { // keep the program running until the user chooses to exit
        printf("\nQueue Implementation using Arrays in C\n");
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
