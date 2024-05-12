#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *findNum(char *pattern) {
    int n = strlen(pattern) + 1;
    char *num = (char *)malloc((n + 1) * sizeof(char));
    int min = 1, max = n;

    num[n] = '\0';
    for (int i = 0; i < n - 1; i++) {
        if (pattern[i] == 'I') {
            num[i] = min++;
        } else {
            num[i] = max--;
        }
    }
    num[n - 1] = min;

    return num;
}

void testFindNum() {
    char *pattern1 = "IIIDIDDD";
    char *result1 = findNum(pattern1);
    printf("Input: \"IIIDIDDD\"\nOutput: \"%s\"\n", result1);
    free(result1);

    char *pattern2 = "DDD";
    char *result2 = findNum(pattern2);
    printf("Input: \"DDD\"\nOutput: \"%s\"\n", result2);
    free(result2);
}

int main() {
    testFindNum();
    return 0;
}