#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

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

void reverseStringWords(char *s) {
    char *buffer = (char*)malloc(strlen(s) * sizeof(char));
    char *bufferPtr = buffer;
    strcpy(buffer, s);

    WordDescriptor word;
    bool isWordFound;
    char *beginSearch = buffer + strlen(buffer) - 1;
    char *resultPtr = s;
    while ((isWordFound = extractWord(&beginSearch, &word)), isWordFound) {
        if (resultPtr != s) {
            *resultPtr = ' ';
            resultPtr++;
        }
        for (int i = word.length - 1; i >= 0; i--) {
            *resultPtr = word.start[i];
            resultPtr++;
        }
    }
    // Завершаем строку
    *resultPtr = '\0';
    free(buffer);
}

void testReverseStringWords() {
    char str[] = "one two three four";
    printf("Исходная строка: %s\n", str);
    reverseStringWords(str);
    printf("Результат: %s\n", str);
}

int main() {
    testReverseStringWords();
    return 0;
}