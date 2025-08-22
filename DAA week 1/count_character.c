#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int count = 0, i;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);   // read string including spaces

    // remove newline character if fgets adds it
    str[strcspn(str, "\n")] = '\0';

    for (i = 0; str[i] != '\0'; i++) {
        count++;
    }

    printf("Total characters: %d\n", count);

    return 0;
}
