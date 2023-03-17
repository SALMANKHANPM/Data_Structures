#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* insert(struct node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    }
    else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

struct node* search(struct node* node, int data) {
    if (node == NULL || node->data == data) {
        return node;
    }
    if (data < node->data) {
        return search(node->left, data);
    }
    else {
        return search(node->right, data);
    }
}

struct node* delete(struct node* node, int data) {
    if (node == NULL) {
        return node;
    }
    if (data < node->data) {
        node->left = delete(node->left, data);
    }
    else if (data > node->data) {
        node->right = delete(node->right, data);
    }
    else {
        if (node->left == NULL) {
            struct node* temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL) {
            struct node* temp = node->left;
            free(node);
            return temp;
        }
        struct node* temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = delete(node->right, temp->data);
    }
    return node;
}

struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

void inorderTraversal(struct node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

int main() {
    struct node* root = NULL;
    int choice, data;

    do {
        printf("\nBinary Search Tree Operations\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display Inorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("%d has been inserted into the BST.\n", data);
                break;
            case 2:
                printf("Enter the value to be deleted: ");
                scanf("%d", &data);
                root = delete(root, data);
                printf("%d has been deleted from the BST.\n", data);
                break;
            case 3:
                printf("Enter the value to be searched: ");
                scanf("%d", &data);
                struct node* searchResult = search(root, data);
                if (searchResult != NULL) {
                    printf("%d was found in the BST.\n", data);
                }
                else {
                    printf("%d was not found in the BST.\n", data);
                }
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }

    } while (choice != 5);

    return 0;
}
