#include <stdio.h>
#include <stdlib.h>

typedef struct HashSet {
    int *set;
    int capacity;
} HashSet;

HashSet *initHashSet(int capacity) {
    HashSet *hashSet = (HashSet *)malloc(sizeof(HashSet));
    hashSet->capacity = capacity;
    hashSet->set = (int *)calloc(capacity, sizeof(int));
    return hashSet;
}

void addToHashSet(HashSet *hashSet, int element) {
    hashSet->set[element] = 1;
}

int contains(HashSet *hashSet, int element) {
    return hashSet->set[element];
}

int main() {
    int n;
    scanf("%d", &n);

    HashSet *watchedSet = initHashSet(n + 1);

    int watchedSeriesCount = n - 1;
    int watchedSeries;

    for (int i = 0; i < watchedSeriesCount; i++) {
        scanf("%d", &watchedSeries);
        addToHashSet(watchedSet, watchedSeries);
    }

    int missingSeries = 0;
    for (int i = 1; i <= n; i++) {
        if (!contains(watchedSet, i)) {
            missingSeries = i;
            break;
        }
    }

    printf("%d\n", missingSeries);

    free(watchedSet->set);
    free(watchedSet);

    return 0;
}
