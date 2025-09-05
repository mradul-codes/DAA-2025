#include <stdio.h>

int Missing(int arr[], int n) {
    int total = n * (n + 1) / 2;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return total - sum;
}

int main() {
    int arr[] = {0, 1, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int missing = Missing(arr, n);
    printf("Missing number is: %d\n", missing);

    return 0;
}