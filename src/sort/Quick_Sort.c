#include <stdio.h>

// Function to perform swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform partition the array using the middle element as pivot
int partition(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    int pivot = arr[mid];
    swap(&arr[mid], &arr[low]); // Move pivot to the beginning 

    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i - 1], &arr[low]);

    return i - 1;
}

// Wrapper function to perform quick sort 
void quickSort(int arr[], int len) {
    quickSort_recursion(arr, 0, len-1);
}

// Function to perform quick sort recursion 
void quickSort_recursion(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quickSort_recursion(arr, low, pivot_index - 1);
        quickSort_recursion(arr, pivot_index + 1, high);
    }
}

int main() {
    int arr[] = {22, 33, 66, 55, 44, 99, 11};
    int len = sizeof(arr) / sizeof(arr[0]);

    // Print the original array
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform quick sort
    quickSort(arr, len);

    // Print the original array
    for (int j = 0; j < len; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");

    return 0;
}