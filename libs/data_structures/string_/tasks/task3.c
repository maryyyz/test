#include <ctype.h>
#include "string_.h"

void digitToStart_(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void getDigitsAtBeginOfLetterAtEnd(char *beginString) {
    char *beginSearch = beginString;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStart_(word);
        beginSearch = word.end;
    }
}

void transformString(char *s) {
    char *start = s;
    char *end = s;

    while (*end) {
        while (*end && !isspace(*end)) {
            end++;
        }

        char *digitPtr = start;
        char *letterPtr = start;

        while (start < end) {
            if (isdigit(*start)) {
                *digitPtr++ = *start++;
            } else {
                start++;
            }
        }

        while (letterPtr < end) {
            if (!isdigit(*letterPtr)) {
                *digitPtr++ = *letterPtr++;
            } else {
                letterPtr++;
            }
        }

        start = end;
        while (*start && isspace(*start)) {
            start++;
        }
        end = start;
    }
}

void test_getDigitsAtBeginOfLetterAtEnd() {
    char source[] = "Hi123 Hello456";
    getDigitsAtBeginOfLetterAtEnd(source);
    ASSERT_STRING("123Hi 456Hello", source);
}

void test_transformString() {
    char str[] = "abc123 def456ghi789";

    transformString(str);

    printf("Transformed string: %s\n", str);
}

void test() {
    test_getDigitsAtBeginOfLetterAtEnd();
    test_transformString();
}

int main() {
    test();

    return 0;
}