#include <stdio.h>

int knapsack(int weights[], int values[], int capacity, int n) {
    if (n == 0 || capacity == 0) {
        return 0;
    }

    if (weights[n - 1] > capacity) {
        return knapsack(weights, values, capacity, n - 1);
    } 
    else {
        int include = values[n - 1] + knapsack(weights, values, capacity - weights[n - 1], n - 1);
        int exclude = knapsack(weights, values, capacity, n - 1);
        return (include > exclude) ? include : exclude;
    }
}

int main() {
    int values[] = {70, 110, 100};
    int weights[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);

    int max = knapsack(weights, values, capacity, n);
    printf("Maximum value  = %d\n", max);

    return 0;
}