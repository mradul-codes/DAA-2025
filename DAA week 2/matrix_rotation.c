#include <stdio.h>

void rotate(int matrix[][100], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Step 2: Reverse each row
    for (i = 0; i < n; i++) {
        for (j = 0; j < n / 2; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }
}

// Utility to print matrix
void Matrix(int matrix[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[100][100] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int n = 3;

    printf("Original Matrix:\n");
    Matrix(matrix, n);

    rotate(matrix, n);

    printf("\nRotated Matrix:\n");
    Matrix(matrix, n);

    return 0;
}