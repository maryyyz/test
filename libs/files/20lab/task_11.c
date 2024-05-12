#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 1003
#define MAX_DICT_SIZE 300005

typedef struct {
    char word[MAX_WORD_LENGTH];
    int index;
} DictionaryEntry;

int compareStrings(const void *a, const void *b) {
    return strcmp(((DictionaryEntry *)a)->word, ((DictionaryEntry *)b)->word);
}

int findWordWithPrefix(DictionaryEntry dict[], int dictSize, char prefix[]) {
    int low = 0, high = dictSize - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strncmp(dict[mid].word, prefix, strlen(prefix));
        if (cmp == 0) {
            return dict[mid].index;
        } else if (cmp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void processQueries(DictionaryEntry dict[], int dictSize, int Q) {
    for (int i = 0; i < Q; i++) {
        int k;
        char prefix[MAX_WORD_LENGTH];
        scanf("%d %s", &k, prefix);
        int index = findWordWithPrefix(dict, dictSize, prefix);
        if (index != -1 && k <= dictSize) {
            printf("%d\n", index);
        } else {
            printf("-1\n");
        }
    }
}

void testProcessQueries() {
    DictionaryEntry dict[] = {
            {"aa", 1},
            {"aaa", 2},
            {"aab", 3},
            {"ab", 4},
            {"abc", 5},
            {"ac", 6},
            {"ba", 7},
            {"daa", 8},
            {"dab", 9},
            {"dadba", 10}
    };
    int dictSize = sizeof(dict) / sizeof(dict[0]);
    int Q = 3;
    processQueries(dict, dictSize, Q);
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    DictionaryEntry dict[MAX_DICT_SIZE];
    for (int i = 0; i < N; i++) {
        scanf("%s", dict[i].word);
        dict[i].index = i + 1;
    }

    qsort(dict, N, sizeof(DictionaryEntry), compareStrings);

    processQueries(dict, N, Q);

    testProcessQueries();

    return 0;
}