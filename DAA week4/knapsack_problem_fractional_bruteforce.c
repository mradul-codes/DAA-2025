#include <stdio.h>

void fractionalKnapsack(int weights[], int values[], int n, int capacity) {
    float ratio[n];
    for (int i = 0; i < n; i++) {
        ratio[i] = (float)values[i] / weights[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                float tempR = ratio[j];
                ratio[j + 1] = tempR;

                int tempW = weights[j];
                weights[j] = weights[j + 1];
                weights[j + 1] = tempW;

                int tempV = values[j];
                values[j] = values[j + 1];
                values[j + 1] = tempV;
            }
        }
    }

    float totalValue = 0.0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (weights[i] <= capacity) {
            totalValue += values[i];
            capacity -= weights[i];
        } else {
            totalValue += ratio[i] * capacity;
            capacity = 0;
        }
    }

    printf("Maximum value in Fractional Knapsack = %.2f\n", totalValue);
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);

    fractionalKnapsack(weights, values, n, capacity);
    return 0;
}