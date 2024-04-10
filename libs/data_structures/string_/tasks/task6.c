#include <stdio.h>
#include <string.h>

typedef struct {
    char *start;
    char *end;
} WordDescriptor;

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    size_t len1 = w1.end - w1.start;
    size_t len2 = w2.end - w2.start;

    if (len1 != len2) {
        return 0;
    }

    for (size_t i = 0; i < len1; i++) {
        if (w1.start[i] != w2.start[i]) {
            return 0;
        }
    }

    return 1;
}

int isLexicographicallyOrdered(char *sentence) {
    WordDescriptor currentWord, previousWord;
    int isFirstWord = 1;

    for (char *ptr = strtok(sentence, " "); ptr != NULL; ptr = strtok(NULL, " ")) {
        currentWord.start = ptr;
        currentWord.end = ptr + strlen(ptr);

        if (isFirstWord) {
            previousWord = currentWord;
            isFirstWord = 0;
            continue;
        }

        if (!areWordsEqual(currentWord, previousWord)) {
            if (strcmp(currentWord.start, previousWord.start) < 0) {
                return 0;
            }
        }

        previousWord = currentWord;
    }

    return 1;
}


void test_isLexicographicallyOrdered() {
    char sentence1[] = "apple banana cherry";
    char sentence2[] = "banana apple cherry";
    char sentence3[] = "apple banana apple";

    printf("Test 1: %s\n", isLexicographicallyOrdered(sentence1) ? "Passed" : "Failed");
    printf("Test 2: %s\n", isLexicographicallyOrdered(sentence2) ? "Passed" : "Failed");
    printf("Test 3: %s\n", isLexicographicallyOrdered(sentence3) ? "Passed" : "Failed");
}

int main() {
    test_isLexicographicallyOrdered();
    return 0;
}