#include <stdio.h>

void shellSort(int arr[], int n){
    int gap, key, i, j;

    for(gap = n/2; gap> 0; gap = gap / 2 ){
        for (i = gap; i < n; i++){
            key = arr[i];

            for( j = i; j >= gap && arr[j - gap] >= key; j -= gap){
                arr[j] = arr[j - gap];
            }

            arr[j] = key;
        }
    }
}

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main () {
    int n;
    printf("Enter the Size of the Array : ");
    scanf("%d", &n);

    int arr[n], i;

    printf("Enter the Array Elements : ");
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    printf("Before Sorting : ");
    printArr(arr, n);

    shellSort(arr, n);

    printf("After Sorting : ");
    printArr(arr, n);

    return 0;
}