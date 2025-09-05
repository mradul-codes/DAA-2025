// by using functions

#include <stdio.h>

int Power(int n) {
    if (n <= 0)
        return 0;
    return (n & (n - 1)) == 0;
}

int main() {
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (Power(n)) {
        printf("%d is a power of two.\n", n);
    } else {
        printf("%d is not a power of two.\n", n);
    }

    return 0;
}

// without using function

// # include<stdio.h>

// int main()
// {
//     int num;
//     printf("enter the no.");
//     scanf("%d",&num);
    
//     if(num%2 ==0 && num>=0){
//         printf("%d is a power of two.\n", num);
//     }
//     else
//     {
//         printf("%d is not a power of two.\n", num);
//     }
// }