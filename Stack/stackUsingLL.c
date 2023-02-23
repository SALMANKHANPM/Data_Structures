// Stack Implementation Using Linked List

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL; // initialize top of the stack to NULL

void push(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); // allocate memory for new node
    new_node->data = value; // set data of new node to value
    new_node->next = top; // set next of new node to current top
    top = new_node; // set top to new node
}

int pop() {
    if (top == NULL) { // check if stack is empty
        printf("Stack underflow!\n");
        return -1;
    }
    struct node* temp = top; // create temporary node to hold current top
    int value = temp->data; // get the data of the current top
    top = top->next; // set top to the next node
    free(temp); // free memory allocated for the old top
    return value; // return the popped value
}

int peek() {
    if (top == NULL) { // check if stack is empty
        printf("Stack is empty!\n");
        return -1;
    }
    return top->data; // return the data of the top node
}

int main() {
    int choice, value;
    while (1) { // keep the program running until the user chooses to exit
        printf("\nStack Implementation using Linked List in C\n");
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
