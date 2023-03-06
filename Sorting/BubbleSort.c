#include <stdio.h>

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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

/* Time Complexity: O(n)
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
    
    bubble_sort(arr, n);
    
    printf("\nAfter sorting: ");
    print_array(arr, n);
    
    return 0;
}
