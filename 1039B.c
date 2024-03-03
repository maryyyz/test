#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>

bool isStringPalindrome(char * const a, const size_t n)
{
    bool answ = true;

    for(size_t i = 0; i < n / 2; i++)
    {
        if(a[i] != a[n - i - 1])
        {
            answ = false;
        }
    }

    return answ;
}

bool isNotPalindromePossible(char * str, size_t size)
{
    bool answ = false;

    for(size_t i = 0; i < size / 2; i++)
    {
        if(str[i] != str[i + 1])
        {
            char temp = str[i];
            str[i] = str[i + 1];
            str[i + 1] = temp;
            answ = true;
            break;
        }
    }
    return answ;
}

int main()
{
    char str[1001];
    int times;
    size_t str_size;

    scanf("%d", &times);
    gets(str);
    // fflush(stdin);

    for(int i = 0; i < times; i++)
    {
        gets(str);

        str_size = strlen(str);

        if(isStringPalindrome(str, str_size) == false)
        {
            printf("%s \n", str);
        }
        else if(isNotPalindromePossible(str, str_size))
        {
            printf("%s \n", str);
        }
        else
        {
            printf("-1 \n");
        }
    }
}