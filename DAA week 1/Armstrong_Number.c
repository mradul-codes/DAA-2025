#include <stdio.h>

int main() {
    int num, original, rem, digits = 0, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;

    int temp = num;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    temp = num;
    while (temp != 0) {
        rem = temp % 10;

        int power = 1;
        for (int i = 0; i < digits; i++) {
            power *= rem;
        }

        sum += power;
        temp /= 10;
    }

    if (sum == original)
        printf("%d is an Armstrong number\n", original);
    else
        printf("%d is not an Armstrong number\n", original);

    return 0;
}
