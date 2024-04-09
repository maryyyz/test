#include <ctype.h>
#include <memory.h>

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