#include <stdio.h>

int stringLength(char *s) {
    int len = 0;
    while (*s) {
        len++;
        s++;
    }
    return len;
}

char* findFirstOccurrence(char *s1, char *s2) {
    char *p1 = s1;
    while (*p1) {
        char *p2 = s2;
        char *match = p1;
        while (*p2 && *p1 == *p2) {
            p1++;
            p2++;
        }
        if (!(*p2)) {
            return match;
        } else {
            p1 = match + 1;
        }
    }
    return NULL;
}

char* findPrecedingWord(char *s, char *word) {
    char *p = s;
    while (p < word && *word != '\0') {
        while (*p == ' ') p++;
        char *start = p;
        while (*p && *p != ' ') p++;
        if (p == word) break;
        char *q = word;
        while (*start && *q && *start == *q) {
            start++;
            q++;
        }
        if (!(*q)) {
            while (*p == ' ') p++;
            if (!(*p) || *p == ' ') return start;
        }
    }
    return NULL;
}

void testFindPrecedingWord(char *s1, char *s2) {
    char *occurrence = findFirstOccurrence(s1, s2);
    if (occurrence != NULL) {
        printf("First occurrence of \"%s\" in \"%s\" is at position %ld\n", s2, s1, occurrence - s1);
        char *precedingWord = findPrecedingWord(s1, occurrence);
        if (precedingWord != NULL) {
            printf("Preceding word is \"");
            while (*precedingWord != ' ' && *precedingWord != '\0') {
                printf("%c", *precedingWord);
                precedingWord++;
            }
            printf("\"\n");
        } else {
            printf("No preceding word found.\n");
        }
    } else {
        printf("Word \"%s\" not found in \"%s\"\n", s2, s1);
    }
}

int main() {
    char s1[] = "This is a test string";
    char s2[] = "is";

    testFindPrecedingWord(s1, s2);

    return 0;
}