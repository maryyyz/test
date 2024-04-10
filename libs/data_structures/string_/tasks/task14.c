#include <stdio.h>
#include <stdbool.h>

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

bool hasSameLetterSetPair(char *s) {
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
    while (*p) {
        while (*p == ' ') p++;
        char *word1Start = p;
        while (*p && *p != ' ') p++;
        while (*p == ' ') p++;
        char *word2Start = p;
        while (*p && *p != ' ') p++;
        bool sameLetterSet = true;
        char *q1 = word1Start;
        char *q2 = word2Start;
        while (*q1 && *q2) {
            if (*q1 != *q2) {
                sameLetterSet = false;
                break;
            }
            q1++;
            q2++;
        }
        if (*q1 != *q2) sameLetterSet = false;
        if (sameLetterSet) return true;
    }

    return false;
}

void test_hasSameLetterSetPair() {
    char s1[] = "hello world";
    char s2[] = "world hello";
    char s3[] = "foo bar baz";

    printf("String \"%s\" has pair of words with same letter set: %s\n", s1, hasSameLetterSetPair(s1) ? "true" : "false");
    printf("String \"%s\" has pair of words with same letter set: %s\n", s2, hasSameLetterSetPair(s2) ? "true" : "false");
    printf("String \"%s\" has pair of words with same letter set: %s\n", s3, hasSameLetterSetPair(s3) ? "true" : "false");
}

int main() {
    test_hasSameLetterSetPair();
    return 0;
}