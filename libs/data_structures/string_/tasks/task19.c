#include <stdio.h>

int wordInString(char *word, char *str) {
    int letters[26] = {0};
    int wordLength = 0;

    while (*word) {
        letters[*word - 'a']++;
        word++;
        wordLength++;
    }

    while (*str) {
        if (letters[*str - 'a'] > 0) {
            letters[*str - 'a']--;
            wordLength--;
        }
        str++;
        if (wordLength == 0) {
            return 1;
        }
    }

    return 0;
}

void testWordInString() {
    char word1[] = "hello";
    char str1[] = "world";
    char str2[] = "hello";

    char word2[] = "programming";
    char str3[] = "grominpargmngmroing";
    char str4[] = "programming is fun";

    printf("Word 1: %s\n", word1);
    printf("String 1: %s\n", str1);
    printf("Word in string 1: %s\n", wordInString(word1, str1) ? "Yes" : "No");
    printf("String 2: %s\n", str2);
    printf("Word in string 2: %s\n", wordInString(word1, str2) ? "Yes" : "No");

    printf("\nWord 2: %s\n", word2);
    printf("String 3: %s\n", str3);
    printf("Word in string 3: %s\n", wordInString(word2, str3) ? "Yes" : "No");
    printf("String 4: %s\n", str4);
    printf("Word in string 4: %s\n", wordInString(word2, str4) ? "Yes" : "No");
}

int main() {
    testWordInString();

    return 0;
}