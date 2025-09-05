#include <stdio.h>

void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int current = arr[i];
        for (int j = i - 1; j >= 0 && arr[j] > current; --j) {
            // Swap the elements
            arr[j] = current;
        }
        arr[i] = current;
    }
}

int main() {
    int arr[] = {4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(int);
    insertion_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}