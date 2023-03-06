#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            printf("Key : %d Found at Index : %d\n", key, mid);
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
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

    int index = binarySearch(arr, n, key);
    
    if (index == -1) {
        printf("Key Not Found in List of Elements.");
    }

    return 0;
}
