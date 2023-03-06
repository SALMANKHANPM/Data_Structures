#include <stdio.h>

void selection_sort(int arr[], int n) {
    int i, j, min_index, temp;
    
    for(i = 0; i < n-1; i++) {
        min_index = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
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
    
    selection_sort(arr, n);
    
    printf("\nAfter sorting: ");
    print_array(arr, n);
    
    return 0;
}
