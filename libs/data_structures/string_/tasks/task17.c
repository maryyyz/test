#include <stdio.h>
#include <stdbool.h>

bool hasDuplicates(char *word) {
    int seen[256] = {0};
    while (*word) {
        if (seen[*word]) {
            return true;
        }
        seen[*word] = 1;
        word++;
    }
    return false;
}

void removeWordsWithDuplicates(char *s) {
    char *start = s;
    char *end = s;
    while (*end) {
        while (*end == ' ') {
            end++;
            start++;
        }
        while (*end && *end != ' ') {
            end++;
        }
        if (hasDuplicates(start)) {
            while (*end) {
                *start = *end;
                start++;
                end++;
            }
            *start = '\0';
            while (*(start - 1) != ' ' && start > s) {
                start--;
            }
        } else {
            start = end;
        }
    }
}

void testRemoveWordsWithDuplicates() {
    char s1[] = "This is a test string with words containing duplicates like book and door";
    char s2[] = "One two three four five";
    char s3[] = "Hello world good morning";
    char s4[] = "This is a test string with words like book and door";

    printf("Original string 1: %s\n", s1);
    removeWordsWithDuplicates(s1);
    printf("String 1 after removing words with duplicates: %s\n\n", s1);

    printf("Original string 2: %s\n", s2);
    removeWordsWithDuplicates(s2);
    printf("String 2 after removing words with duplicates: %s\n\n", s2);

    printf("Original string 3: %s\n", s3);
    removeWordsWithDuplicates(s3);
    printf("String 3 after removing words with duplicates: %s\n\n", s3);

    printf("Original string 4: %s\n", s4);
    removeWordsWithDuplicates(s4);
    printf("String 4 after removing words with duplicates: %s\n\n", s4);
}

int main() {
    testRemoveWordsWithDuplicates();

    return 0;
}