#include <stdio.h>

typedef struct {
    char *start;
    int length;
} WordDescriptor;

int stringLength(char *s) {
    int len = 0;
    while (*(s++)) len++;
    return len;
}

void stringCopy(char *src, char *dest) {
    while ((*dest++ = *src++));
}

void sortWord(char *word) {
    int len = stringLength(word);
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (*(word + j) > *(word + j + 1)) {
                char temp = *(word + j);
                *(word + j) = *(word + j + 1);
                *(word + j + 1) = temp;
            }
        }
    }
}

void formStringWithoutLastWord(char *s, char *result) {
    char buffer[1000];
    stringCopy(s, buffer);

    char *p = buffer;
    while (*p) {
        while (*p == ' ') p++;
        char *wordStart = p;
        while (*p && *p != ' ') p++;
        sortWord(wordStart);
    }

    p = buffer;
    char *q = result;
    while (*p) {
        while (*p == ' ') p++;
        char *wordStart = p;
        while (*p && *p != ' ') p++;
        if (*p) {
            while (wordStart < p) {
                *(q++) = *(wordStart++);
            }
            *(q++) = ' ';
        }
    }
    *q = '\0';
}

void test_formStringWithoutLastWord() {
    char s1[] = "hello world";
    char s2[] = "world hello";
    char s3[] = "foo bar baz";
    char result[1000];

    formStringWithoutLastWord(s1, result);
    printf("String \"%s\" without last word: \"%s\"\n", s1, result);

    formStringWithoutLastWord(s2, result);
    printf("String \"%s\" without last word: \"%s\"\n", s2, result);

    formStringWithoutLastWord(s3, result);
    printf("String \"%s\" without last word: \"%s\"\n", s3, result);
}

int main() {
    test_formStringWithoutLastWord();
    return 0;
}