#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct {
    char *start;
    int length;
} WordDescriptor;

bool extractWord(char **beginSearch, WordDescriptor *word) {
    char *current = *beginSearch;
    while (*current == ' ') {
        current++;
    }
    if (*current == '\0') {
        return false;
    }
    word->start = current;
    while (*current != ' ' && *current != '\0') {
        current++;
    }
    word->length = current - word->start;
    *beginSearch = current;
    return true;
}

char* alternateStrings(char *s1, char *s2) {
    int len1 = 0, len2 = 0;
    while (s1[len1] != '\0') {
        len1++;
    }
    while (s2[len2] != '\0') {
        len2++;
    }

    char *result = (char*)malloc((len1 + len2 + 1) * sizeof(char));

    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    char *resultPtr = result;
    while ((isW1Found = extractWord(&beginSearch1, &word1)),
            (isW2Found = extractWord(&beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            for (int i = 0; i < word1.length; i++) {
                *resultPtr = word1.start[i];
                resultPtr++;
            }
            *resultPtr = ' ';
            resultPtr++;
        }
        if (isW2Found) {
            for (int i = 0; i < word2.length; i++) {
                *resultPtr = word2.start[i];
                resultPtr++;
            }
            *resultPtr = ' ';
            resultPtr++;
        }
    }
    *resultPtr = '\0';
    return result;
}

void test_AlternateStrings() {
    char str1[] = "one two three";
    char str2[] = "four five six seven";
    char *result = alternateStrings(str1, str2);
    printf("Результат: %s\n", result);
    free(result);
}

int main() {
    test_AlternateStrings();
    return 0;
}