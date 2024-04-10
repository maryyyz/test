#include <stdio.h>

int countWords(char *str) {
    int count = 0;
    int inWord = 0;
    while (*str) {
        if (*str == ' ') {
            inWord = 0;
        } else if (!inWord) {
            count++;
            inWord = 1;
        }
        str++;
    }
    return count;
}

void appendWords(char *smaller, char *larger) {
    while (*smaller) {
        if (*smaller == ' ') {
            smaller++;
        } else {
            while (*larger && *larger != ' ') {
                larger++;
            }
            while (*larger == ' ') {
                larger++;
            }
            while (*larger && *larger != ' ') {
                *smaller = *larger;
                smaller++;
                larger++;
            }
        }
    }
    while (*larger) {
        *smaller = *larger;
        smaller++;
        larger++;
    }
    *smaller = '\0';
}

void test_AppendWords() {
    char s1[100] = "This is a test string";
    char s2[100] = "One two three four five";
    char s3[100] = "Hello world good morning";

    printf("Original strings:\n");
    printf("String 1: %s\n", s1);
    printf("String 2: %s\n", s2);
    printf("String 3: %s\n", s3);

    int count1 = countWords(s1);
    int count2 = countWords(s2);
    int count3 = countWords(s3);

    if (count1 < count2) {
        appendWords(s1, s2);
    } else {
        appendWords(s2, s1);
    }

    if (count1 < count3) {
        appendWords(s1, s3);
    } else {
        appendWords(s3, s1);
    }

    if (count2 < count3) {
        appendWords(s2, s3);
    } else {
        appendWords(s3, s2);
    }

    printf("\nAfter appending:\n");
    printf("String 1: %s\n", s1);
    printf("String 2: %s\n", s2);
    printf("String 3: %s\n", s3);
}

int main() {
    test_AppendWords();

    return 0;
}