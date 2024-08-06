#include <stdio.h>

// Function to perform binaru search recursively
int binarySearchRecursive(int arr[], int l, int r, int key) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        // If the element is present at the middle
        if (arr[mid] == key) {
            return mid;
        }
        // If the element is smaller than the middle element, then ignore the right half
        if (arr[mid] > key) {
            return binarySearchRecursive(arr, l, mid - 1, key);
        }
        // Else the element can only be in the right half
        else {
            return binarySearchRecursive(arr, mid + 1, r, key);
        }
    }
    // Element is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 10;
    int result = binarySearchRecursive(arr, 0, n - 1, x);
    if(result != -1)
        printf("Element is present at index %d", result);
    else
        printf("Element is not present in array");
    return 0;
}