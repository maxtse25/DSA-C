#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 80, 30, 60, 50, 110, 100, 130, 170};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
    int key = 110; // The element to search for

    int result = linearSearch(arr, n, key); // Perform linear search
    if (result != -1)
        printf("Element is found at index: %d\n", result);
    else
        printf("Element is not found in the array.\n");

    return 0;
}