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
