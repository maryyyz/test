#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *p = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    for (int a = 1; a <= n; a++) {
        int current = a;
        int visited[n + 1];
        for (int i = 0; i <= n; i++) {
            visited[i] = 0;
        }
        int second_hole = -1;

        while (!visited[current]) {
            visited[current] = 1;
            current = p[current - 1];
        }

        // Теперь current указывает на школьника, которому будет поставлена вторая дырка
        second_hole = current;
        printf("%d ", second_hole);
    }

    free(p);
    return 0;
}