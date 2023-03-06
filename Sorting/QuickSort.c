#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for(int j = low; j <= high-1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quick_sort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}

void print_array(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Before sorting: ");
    print_array(arr, n);
    
    quick_sort(arr, 0, n-1);
    
    printf("\nAfter sorting: ");
    print_array(arr, n);
    
    return 0;
}
