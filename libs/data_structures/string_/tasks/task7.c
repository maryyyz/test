#include <stdio.h>

#define MAX_N_WORDS_IN_STRING 100

typedef struct {
    char *start;
    char *end;
} WordDescriptor;

typedef struct {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

BagOfWords _bag;

void getBagOfWords(BagOfWords *bag, char *s) {
    bag->size = 0;
    char *ptr = s;
    char *word_start = NULL;

    while (*ptr != '\0') {
        if ((*ptr != ' ') && (ptr == s || *(ptr - 1) == ' ')) {
            word_start = ptr;
        }
        if ((*ptr != ' ') && (*(ptr + 1) == ' ' || *(ptr + 1) == '\0')) {
            bag->words[bag->size].start = word_start;
            bag->words[bag->size].end = ptr;
            bag->size++;
        }
        ptr++;
    }
}

void test_getBagOfWords() {
    char sentence[] = "This is a test sentence";

    getBagOfWords(&_bag, sentence);

    printf("BagOfWords size: %zu\n", _bag.size);
    for (size_t i = 0; i < _bag.size; i++) {
        printf("Word %zu: start=%p, end=%p\n", i, (void*)_bag.words[i].start, (void*)_bag.words[i].end);
    }
}

int main() {
    test_getBagOfWords();

    return 0;
}