#include <stdio.h>

#define ROWS 3
#define COLS 3

void sortArray(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void medianFilter(int matrix[][COLS], int filter) {
    int window[filter * filter];

    for (int i = filter / 2; i < ROWS - filter / 2; i++) {
        for (int j = filter / 2; j < COLS - filter / 2; j++) {
            int index = 0;

            for (int k = -filter / 2; k <= filter / 2; k++) {
                for (int l = -filter / 2; l <= filter / 2; l++) {
                    window[index++] = matrix[i + k][j + l];
                }
            }

            sortArray(window, filter * filter);

            matrix[i][j] = window[filter * filter / 2];
        }
    }
}

void printMatrix(int matrix[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void testMedianFilter() {
    int matrix[ROWS][COLS] = {
            {10, 20, 30},
            {25, 35, 45},
            {15, 25, 35}
    };

    printf("Original Matrix:\n");
    printMatrix(matrix);

    int filter = 3;

    medianFilter(matrix, filter);

    printf("\nFiltered Matrix:\n");
    printMatrix(matrix);
}

int main() {
    testMedianFilter();
    return 0;
}