#include <stdio.h>

int main() {
    int n, k, i, j;
    int arr[100], temp[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value of k (number of rotations): ");
    scanf("%d", &k);

    k = k % n;   // if k > n, wrap around

    // store first k elements in temp
    for (i = 0; i < k; i++) {
        temp[i] = arr[i];
    }

    // shift remaining elements to the left
    for (i = k; i < n; i++) {
        arr[i - k] = arr[i];
    }

    // copy temp elements to end
    for (i = 0; i < k; i++) {
        arr[n - k + i] = temp[i];
    }

    printf("Array after %d left rotations:\n", k);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
