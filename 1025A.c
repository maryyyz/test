#include <stdio.h>

int main() {
    int n, i, count, z = 0;

    while (scanf("%d", &n) != EOF) {
        getchar();

        char a[n];
        for (i = 0; i < n; i++) {
            scanf("%c", &a[i]);
        }

        int exists[26] = {0};

        int duplicate = 0;

        for (i = 0; i < n; i++) {
            int index = (int)(a[i] - 'a');
            if (exists[index] == 1) {
                duplicate = 1;
                break;
            }
            exists[index] = 1;
        }

        if (duplicate == 1 || n == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}