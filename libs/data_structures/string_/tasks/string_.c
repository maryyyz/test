#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include "string_.h"

size_t stringLength(const char *str) {
    const char *ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - str;
}

size_t my_strlen(const char *str) {
    const char *ptr = str;

    while (*ptr != '\0') {
        ptr++;
    }

    return (size_t)(ptr - str);
}

char* find(char *begin, char *end, int ch) {
    while (begin != end) {
        if (*begin == ch) {
            return begin;
        }
        begin++;
    }
    return end;
}

char* findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin)) {
        begin++;
    }
    return begin;
}

char* findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin)) {
        begin++;
    }
    return begin;
}

char* findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*(rbegin - 1))) {
        rbegin--;
    }
    return rbegin;
}

char* findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*(rbegin - 1))) {
        rbegin--;
    }
    return rbegin;
}

int my_strcmp(const char *lhs, const char *rhs) {
    while (*lhs && *rhs && *lhs == *rhs) {
        lhs++;
        rhs++;
    }
    return *lhs - *rhs;
}

char* copy(const char *beginSource, const char *endSource, char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource);

    return beginDestination + (endSource - beginSource);
}

char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    char *dest = beginDestination;

    while (beginSource < endSource) {
        if (f(*beginSource)) {
            *dest++ = *beginSource;
        }
        beginSource++;
    }

    return dest;
}

int isAlpha(int c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    char *dest = beginDestination;

    while (rbeginSource >= rendSource) {
        if (f(*rbeginSource)) {
            *dest = *rbeginSource;
            dest--;
        }
        rbeginSource--;
    }

    return beginDestination;
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

char* getEndOfString(char* s) {
    char* end = s;

    while(*end) {
        end++;
    }

    end--;

    return end;
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = rbegin;
    word->begin = findSpaceReverse(rbegin, rend);

    if (word->begin == rend)
        return 0;

    word->begin = findNonSpaceReverse(word->begin, rend);

    return 1;
}

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1, _stringBuffer - 1, word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void assertString(const char *expected, char *got,char const *fileName, char const *funcName, int line) {
    if (strcmp(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}