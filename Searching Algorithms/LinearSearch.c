#include <stdio.h>

int linearSearch(int arr[], int n, int key){
    for (int i = 0; i < n; i++){
        if (arr[i] == key){
            printf("Key : %d Found at Index : %d ", key, i);
            return i;
        }
    }
    return -1;
}

int main () {
    int n;
    printf("Enter Size of the Array : ");
    scanf("%d", &n);

    int arr[n], i;
    printf("Enter the Array Elements : ");
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the Key to be Searched : ");
    scanf("%d", &key);

    int index = linearSearch(arr, n, key);
    if (index == -1) {
        printf("Key Not Found in List of Elements.");
    }

    return 0;
}
