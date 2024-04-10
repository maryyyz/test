#include <stdio.h>

void removeExtraSpaces(char *s) {
    char *current = s;
    int previousSpace = 0;

    while (*s) {
        if (*s != ' ') {
            *current++ = *s++;
            previousSpace = 0;
        }
        else if (!previousSpace) {
            *current++ = *s++;
            previousSpace = 1;
        }
        else {
            s++;
        }
    }

    *current = '\0';
}

void test_removeExtraSpaces() {
    char str[] = "   Hello    world!   ";

    removeExtraSpaces(str);

    printf("Result: '%s'\n", str);
}

int main() {
    test_removeExtraSpaces();
    return 0;
}