#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

void replaceDigitsWithSpaces(char *s) {
    char buffer[MAX_STRING_SIZE];
    strcpy(buffer, s);

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (isdigit(buffer[i])) {
            int numSpaces = buffer[i] - '0';
            memmove(&s[i + numSpaces], &s[i + 1], strlen(&s[i + 1]) + 1);
            memset(&s[i], ' ', numSpaces);
        }
    }
}

void test_replaceDigitsWithSpaces() {
    char str[MAX_STRING_SIZE] = "abc123def45ghi";

    replaceDigitsWithSpaces(str);

    printf("Result: %s\n", str);
}

int main() {
    test_replaceDigitsWithSpaces();
    return 0;
}