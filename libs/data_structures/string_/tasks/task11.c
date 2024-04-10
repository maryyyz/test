#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char *start;
    int length;
} WordDescriptor;

typedef enum {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

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

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *w) {
    WordDescriptor word;
    bool isWordFound = false;
    char *beginSearch = s;
    while (extractWord(&beginSearch, &word)) {
        char *currentLetter = word.start;
        bool containsA = false;
        while (*currentLetter != '\0') {
            if (*currentLetter == 'a' || *currentLetter == 'A') {
                containsA = true;
                break;
            }
            currentLetter++;
        }
        if (containsA) {
            return isWordFound ? WORD_FOUND : FIRST_WORD_WITH_A;
        }
        if (!isWordFound) {
            *w = word;
            isWordFound = true;
        }
    }
    return isWordFound ? NOT_FOUND_A_WORD_WITH_A : EMPTY_STRING;
}

void test_getWordBeforeFirstWordWithA() {
    WordDescriptor word;

    char s1[] = "";
    WordBeforeFirstWordWithAReturnCode code1 = getWordBeforeFirstWordWithA(s1, &word);
    printf("Test Case 1: ");
    switch (code1) {
        case EMPTY_STRING:
            printf("Empty string.\n");
            break;
        case NOT_FOUND_A_WORD_WITH_A:
            printf("No word containing 'a'.\n");
            break;
        case FIRST_WORD_WITH_A:
            printf("First word contains 'a'.\n");
            break;
        case WORD_FOUND:
            printf("Word before first word with 'a': %.*s\n", word.length, word.start);
            break;
    }

    char s2[] = "ABC";
    WordBeforeFirstWordWithAReturnCode code2 = getWordBeforeFirstWordWithA(s2, &word);
    printf("Test Case 2: ");
    switch (code2) {
        case EMPTY_STRING:
            printf("Empty string.\n");
            break;
        case NOT_FOUND_A_WORD_WITH_A:
            printf("No word containing 'a'.\n");
            break;
        case FIRST_WORD_WITH_A:
            printf("First word contains 'a'.\n");
            break;
        case WORD_FOUND:
            printf("Word before first word with 'a': %.*s\n", word.length, word.start);
            break;
    }

    char s3[] = "BC A";
    WordBeforeFirstWordWithAReturnCode code3 = getWordBeforeFirstWordWithA(s3, &word);
    printf("Test Case 3: ");
    switch (code3) {
        case EMPTY_STRING:
            printf("Empty string.\n");
            break;
        case NOT_FOUND_A_WORD_WITH_A:
            printf("No word containing 'a'.\n");
            break;
        case FIRST_WORD_WITH_A:
            printf("First word contains 'a'.\n");
            break;
        case WORD_FOUND:
            printf("Word before first word with 'a': %.*s\n", word.length, word.start);
            break;
    }

    char s4[] = "B Q WE YR OW IUWR";
    WordBeforeFirstWordWithAReturnCode code4 = getWordBeforeFirstWordWithA(s4, &word);
    printf("Test Case 4: ");
    switch (code4) {
        case EMPTY_STRING:
            printf("Empty string.\n");
            break;
        case NOT_FOUND_A_WORD_WITH_A:
            printf("No word containing 'a'.\n");
            break;
        case FIRST_WORD_WITH_A:
            printf("First word contains 'a'.\n");
            break;
        case WORD_FOUND:
            printf("Word before first word with 'a': %.*s\n", word.length, word.start);
            break;
    }
}

int main() {
    test_getWordBeforeFirstWordWithA();
    return 0;
}