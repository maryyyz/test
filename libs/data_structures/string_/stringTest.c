#include <stdio.h>
#include "string_.h"

void test_stringLength() {
    const char *test_strings[] = {
            "Hello",
            "World",
            "Test",
            "",
            "1234567890"
    };

    size_t expected_results[] = {5, 5, 4, 0, 10};

    for (int i = 0; i < sizeof(test_strings) / sizeof(test_strings[0]); ++i) {
        size_t result = stringLength(test_strings[i]);

        if (result == expected_results[i]) {
            printf("Test %d Passed\n", i+1);
        } else {
            printf("Test %d Failed. Expected: %zu, Got: %zu\n", i+1, expected_results[i], result);
        }
    }
}

void test_my_strlen() {
    const char *test_strings[] = {
            "Hello",
            "World",
            "Test",
            "",
            "1234567890"
    };

    const size_t expected_results[] = {5, 5, 4, 0, 10};

    for (int i = 0; i < sizeof(test_strings) / sizeof(test_strings[0]); ++i) {
        size_t result = my_strlen(test_strings[i]);

        if (result == expected_results[i]) {
            printf("Test %d Passed\n", i+1);
        } else {
            printf("Test %d Failed. Expected: %zu, Got: %zu\n", i+1, expected_results[i], result);
        }
    }
}

void test_find() {
    char test_string[] = "Hello, World!";
    char *begin = test_string;
    char *end = test_string + sizeof(test_string) - 1;

    char *found_o = find(begin, end, 'o');
    char *found_x = find(begin, end, 'x');

    if (found_o != end) {
        printf("Found 'o' at index: %ld\n", found_o - begin);
    } else {
        printf("Character 'o' not found.\n");
    }

    if (found_x != end) {
        printf("Found 'x' at index: %ld\n", found_x - begin);
    } else {
        printf("Character 'x' not found.\n");
    }
}

void test_findNonSpace() {
    char test_string[] = "   Hello, World!   ";
    char *begin = test_string;

    char *found_non_space = findNonSpace(begin);

    if (*found_non_space != '\0') {
        printf("First non-space character found at index: %ld\n", found_non_space - begin);
    } else {
        printf("No non-space characters found.\n");
    }
}

void test_findSpace() {
    char test_string[] = "Hello, World!   ";
    char *begin = test_string;

    char *found_space = findSpace(begin);

    if (*found_space != '\0') {
        printf("First space character found at index: %ld\n", found_space - begin);
    } else {
        printf("No space characters found.\n");
    }
}

void test_findNonSpaceReverse() {
    char test_string[] = "   Hello, World!   ";
    char *rbegin = test_string + sizeof(test_string) - 1;
    const char *rend = test_string - 1;

    char *found_non_space_reverse = findNonSpaceReverse(rbegin, rend);

    if (found_non_space_reverse != rend) {
        printf("Last non-space character found at index: %ld\n", rbegin - found_non_space_reverse - 1);
    } else {
        printf("No non-space characters found.\n");
    }
}

void test_findSpaceReverse() {
    char test_string[] = "   Hello, World!   ";
    char *rbegin = test_string + sizeof(test_string) - 1;
    const char *rend = test_string - 1;

    char *found_space_reverse = findSpaceReverse(rbegin, rend);

    if (found_space_reverse != rend) {
        printf("Last space character found at index: %ld\n", rbegin - found_space_reverse - 1);
    } else {
        printf("No space characters found.\n");
    }
}