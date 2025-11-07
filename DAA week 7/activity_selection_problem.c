#include<stdio.h>
#define n 6

void activitySelection(int start[], int finish[]) {
    int i = 0;
    printf("Selected activities:\n%d ", i);

    for (int j = 1; j < n; j++) {
        if (start[j] >= finish[i]) {
            printf("%d ", j);
            i = j;
        }
    }
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    activitySelection(start, finish);
    return 0;
}