#include <stdio.h>

// Function to perform binary search iteratively
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (x == arr[m]) {
            return m;
        }
        // If x is greater than the middle element, ignore the left half
        if (x > arr[m]) {
            l = m + 1;
        }
        // If x is smaller than the middle element, ignore the right half
        else {
            r = m - 1;
        }
    }
    // Return -1 if the element was not present
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if(result != -1)
        printf("Element is present at index %d", result);
    else
        printf("Element is not present in array");
    return 0;
}