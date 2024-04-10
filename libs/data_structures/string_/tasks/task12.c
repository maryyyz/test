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

void wordDescriptorToString(WordDescriptor word, char *destination) {
    int i;
    for (i = 0; i < word.length; i++) {
        *(destination + i) = *(word.start + i);
    }
    *(destination + i) = '\0';
}

WordDescriptor lastWordInFirstStringInSecondString(char *s1, char *s2) {
    int len1 = stringLength(s1);
    int len2 = stringLength(s2);

    char *p1 = s1 + len1 - 1;
    while (p1 >= s1 && *p1 != ' ') p1--;
    char *end = p1;

    while (p1 >= s1) {
        while (p1 >= s1 && *p1 == ' ') p1--;
        char *start = p1;
        while (start >= s1 && *start != ' ') start--;
        start++;
        char *p2 = s2;
        while (*start && *p2 && *start == *p2) {
            start++;
            p2++;
        }
        if (!(*start) && (!(*p2) || *p2 == ' ')) {
            WordDescriptor word = {p1 + 1, end - p1};
            return word;
        }
        end = p1 - 1;
    }

    WordDescriptor empty = {NULL, 0};
    return empty;
}

void test_lastWordInFirstStringInSecondString() {
    char s1[] = "hello world";
    char s2[] = "foo bar world";

    WordDescriptor word = lastWordInFirstStringInSecondString(s1, s2);

    char string[20];
    wordDescriptorToString(word, string);

    printf("Last word from first string found in second string: %s\n", string);
}

int main() {
    test_lastWordInFirstStringInSecondString();
    return 0;
}