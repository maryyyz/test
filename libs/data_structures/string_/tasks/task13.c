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

int hashWord(char *word) {
    int hash = 0;
    while (*word) {
        hash = (hash * 31 + *word) % 1000000007;
        word++;
    }
    return hash;
}

bool compareWords(WordDescriptor word1, WordDescriptor word2) {
    if (word1.length != word2.length) return false;
    for (int i = 0; i < word1.length; i++) {
        if (*(word1.start + i) != *(word2.start + i)) return false;
    }
    return true;
}

bool hasDuplicateWords(char *s) {
    int len = stringLength(s);

    char *p1 = s + len - 1;
    WordDescriptor currentWord = {NULL, 0};
    while (p1 >= s) {
        while (p1 >= s && *p1 == ' ') p1--;
        char *end = p1;
        while (p1 >= s && *p1 != ' ') p1--;
        currentWord.start = p1 + 1;
        currentWord.length = end - p1;
        char *p2 = s;
        while (p2 < p1) {
            WordDescriptor previousWord = {NULL, 0};
            while (*p2 == ' ') p2++;
            char *end2 = p2;
            while (*p2 && *p2 != ' ') p2++;
            previousWord.start = end2;
            previousWord.length = p2 - end2;
            if (compareWords(currentWord, previousWord)) return true;
        }
    }
    return false;
}

void test_hasDuplicateWords() {
    char s1[] = "hello world world";
    char s2[] = "foo bar baz";

    printf("String \"%s\" has duplicate words: %s\n", s1, hasDuplicateWords(s1) ? "true" : "false");
    printf("String \"%s\" has duplicate words: %s\n", s2, hasDuplicateWords(s2) ? "true" : "false");
}

int main() {
    test_hasDuplicateWords();
    return 0;
}