#include <stdio.h>
#include <stdlib.h>

char *shuffleString(char *s, int *indices, int indicesSize) {
    char *result = (char *)malloc((indicesSize + 1) * sizeof(char));
    for (int i = 0; i < indicesSize; i++) {
        result[indices[i]] = s[i];
    }
    result[indicesSize] = '\0';
    return result;
}

void testShuffleString() {
    char *s1 = "abc";
    int indices1[] = {0, 1, 2};
    char *result1 = shuffleString(s1, indices1, sizeof(indices1) / sizeof(indices1[0]));
    printf("Input: s = \"abc\", indices = [0, 1, 2]\nOutput: %s\n", result1);
    free(result1);

    char *s2 = "abap";
    int indices2[] = {0, 3, 2, 1};
    char *result2 = shuffleString(s2, indices2, sizeof(indices2) / sizeof(indices2[0]));
    printf("Input: s = \"abap\", indices = [0, 3, 2, 1]\nOutput: %s\n", result2);
    free(result2);
}

int main() {
    testShuffleString();
    return 0;
}