#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

struct Node {
    char* key;
    char* value;
    struct Node* next;
};

struct HashTable {
    struct Node* table[TABLE_SIZE];
};

int hash(char* key) {
    int hash = 0;
    while (*key) {
        hash = (hash + *key) % TABLE_SIZE;
        key++;
    }
    return hash;
}

void put(struct HashTable* ht, char* key, char* value) {
    int index = hash(key);
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    newNode->next = NULL;
    switch (ht->table[index] != NULL) {
        case 0:
            ht->table[index] = newNode;
            break;
        case 1:
            struct Node* currNode = ht->table[index];
            while (currNode->next != NULL) {
                currNode = currNode->next;
            }
            currNode->next = newNode;
            break;
    }
}

char* get(struct HashTable* ht, char* key) {
    int index = hash(key);
    struct Node* currNode = ht->table[index];
    while (currNode != NULL) {
        if (strcmp(currNode->key, key) == 0) {
            return currNode->value;
        }
        currNode = currNode->next;
    }
    return NULL;
}

int main() {
    struct HashTable ht;
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht.table[i] = NULL;
    }
    int choice = 0;
    while (choice != 3) {
        printf("Please choose an option:\n");
        printf("1. Add a key-value pair\n");
        printf("2. Get a value by key\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key: ");
                char key[100];
                scanf("%s", key);
                printf("Enter value: ");
                char value[100];
                scanf("%s", value);
                put(&ht, key, value);
                break;
            case 2:
                printf("Enter key: ");
                char searchKey[100];
                scanf("%s", searchKey);
                char* searchValue = get(&ht, searchKey);
                if (searchValue != NULL) {
                    printf("Value for key %s is %s\n", searchKey, searchValue);
                } else {
                    printf("Key not found\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
