#include <stdio.h>

int main()
{
    int n, count = 0;
    int num[26] = {0};

    char str[21];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        num[str[0] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (num[i] > 0) {
            int x = num[i] / 2;
            int y = num[i] - x;
            count += (x * (x - 1) / 2) + (y * (y - 1) / 2);
        }
    }

    printf("%d", count);

    return 0;
}