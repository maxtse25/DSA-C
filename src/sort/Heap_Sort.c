#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* Build a Max Heap form the unordered array. A Max Heap is a complete binary tree where the value of each node is greater than or equal to the values of its children. This ensure that the largest value is at the root of the heap. */

/* `n`: The number of elements in the heap
`i`: The index of the current node */
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main functon to do heap sort 
void heapSort(int arr[], int n) {
    // Build a max-heap from an unordered array
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // Extract elements from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to the end
        swap(&arr[0], &arr[i]);
        
        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Utility function to print array of size n
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array is \n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array is \n");
    printArray(arr, n);
}