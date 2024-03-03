#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char colors[101];
    scanf("%s", colors);

    int count[26] = {0};
    for (int i = 0; i < n; i++) {
        count[colors[i] - 'a']++;
    }

    bool possible = true;
    for (int i = 0; i < 26; i++) {
        if (count[i] > k) {
            possible = false;
            break;
        }
    }

    if (possible) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
