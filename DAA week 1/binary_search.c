#include <stdio.h>

int main() {
    int n, key, i;
    int arr[100];   // maximum size of array

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int low = 0, high = n - 1, mid;
    int found = 0;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            printf("Element %d found at position %d\n", key, mid + 1);
            found = 1;
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}
