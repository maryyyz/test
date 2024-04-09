#include <stdio.h>
#include <ctype.h>

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