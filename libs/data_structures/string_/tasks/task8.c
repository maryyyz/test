#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(char *str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int countPalindromes(char *str) {
    int count = 0;
    int start = 0;
    int end = 0;
    bool inPalindrome = false;

    while (str[end] != '\0') {
        if (((str[end] >= 'a' && str[end] <= 'z') || (str[end] >= 'A' && str[end] <= 'Z')) &&
            ((end == 0 || str[end - 1] == ',') || (str[end + 1] == ',' || str[end + 1] == '\0'))) {
            if (!inPalindrome) {
                start = end;
                inPalindrome = true;
            }
        } else {
            if (inPalindrome) {
                inPalindrome = false;
                if (isPalindrome(str, start, end - 1)) {
                    count++;
                }
            }
        }
        end++;
    }

    if (inPalindrome && end > start && isPalindrome(str, start, end - 1)) {
        count++;
    }

    return count;
}

void test_CountPalindromes() {
    char str1[] = "level, radar, hello, bob";
    int palindromeCount1 = countPalindromes(str1);
    printf("Строка: \"%s\"\n", str1);
    printf("Количество палиндромов: %d\n", palindromeCount1);

    char str2[] = "hello, world, civic, racecar";
    int palindromeCount2 = countPalindromes(str2);
    printf("\nСтрока: \"%s\"\n", str2);
    printf("Количество палиндромов: %d\n", palindromeCount2);
}

int main() {
    test_CountPalindromes();
    return 0;
}