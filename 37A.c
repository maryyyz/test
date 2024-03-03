#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int lengths[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &lengths[i]);
    }

    int count = 0;
    int max_height = 0;
    int unique_lengths[1001] = {0};

    for (int i = 0; i < N; i++) {
        unique_lengths[lengths[i]]++;
    }

    for (int i = 0; i < 1001; i++) {
        if (unique_lengths[i] > 0) {
            count++;
            if (unique_lengths[i] > max_height) {
                max_height = unique_lengths[i];
            }
        }
    }

    printf("%d %d\n", max_height, count);

    return 0;
}