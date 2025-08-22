#include <stdio.h>
#include <ctype.h>   // for toupper()

int main() {
    char str[100];
    int i;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);   // convert each char to uppercase
    }

    printf("Uppercase string: %s", str);

    return 0;
}
