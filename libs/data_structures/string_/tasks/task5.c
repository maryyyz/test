#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 100

typedef struct {
    char *start;
    char *end;
} WordDescriptor;

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen(w1);
    size_t w2Size = strlen(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};
    char _stringBuffer[MAX_STRING_SIZE];
    char *readPtr, *recPtr;

    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        strcpy(_stringBuffer, source);
        readPtr = _stringBuffer;
        recPtr = source;
    }

    while ((recPtr = strstr(recPtr, word1.start)) != NULL) {
        size_t tailLength = strlen(recPtr + w1Size);
        strncpy(readPtr, source, recPtr - source);
        strncpy(readPtr + (recPtr - source), word2.start, word2.end - word2.start);
        readPtr += (recPtr - source) + (word2.end - word2.start);
        source = recPtr + w1Size;
        recPtr += w1Size;
        strcpy(readPtr, recPtr);
        recPtr += tailLength;
    }

    strcpy(readPtr, recPtr);
}

void test_replace() {
    char str[MAX_STRING_SIZE] = "apple orange apple orange";
    char w1[] = "apple";
    char w2[] = "banana";
    replace(str, w1, w2);
    printf("Result: %s\n", str);
}

int main() {
    test_replace();
    return 0;
}