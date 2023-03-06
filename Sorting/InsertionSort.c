#include <stdio.h>

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

/* Time Complexity: O(n)
 * Space Complexity: O(1) */
void print_array(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

/* Time Complexity: O(n^2)
 * Space Complexity: O(n) */
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
    
    insertion_sort(arr, n);
    
    printf("\nAfter sorting: ");
    print_array(arr, n);
    
    return 0;
}
