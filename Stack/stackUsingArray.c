// Stack Implementation using Arrays in C

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1; // initialize top to -1 indicating an empty stack

void push(int value) {
    if (top == MAX_SIZE - 1) { // check if stack is full
        printf("Stack overflow!\n");
        return;
    }
    top++; // increment top
    stack[top] = value; // add value to the top of the stack
}

int pop() {
    if (top == -1) { // check if stack is empty
        printf("Stack underflow!\n");
        return -1;
    }
    int value = stack[top]; // get the value at the top of the stack
    top--; // decrement top
    return value; // return the popped value
}

int peek() {
    if (top == -1) { // check if stack is empty
        printf("Stack is empty!\n");
        return -1;
    }
    return stack[top]; // return the value at the top of the stack
}

int main() {
    int choice, value;
    while (1) { // keep the program running until the user chooses to exit
        printf("\nStack Implementation using Arrays in C\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                value = pop();
                if (value != -1) { // check if pop was successful
                    printf("Popped value is %d\n", value);
                }
                break;

            case 3:
                value = peek();
                if (value != -1) { // check if peek was successful
                    printf("Top value is %d\n", value);
                }
                break;

            case 4:
                exit(0); // exit the program

            default:
                printf("Invalid choice!\n");
        }
    }
}
