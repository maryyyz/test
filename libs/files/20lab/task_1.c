#include <stdio.h>
#include <stdlib.h>

void addSubmatrix(int **matrix, int row1, int col1, int row2, int col2, int n) {
    matrix[row1][col1] += 1;
    matrix[row2][col2] += 1;
    if (col2 + 1 < n)
        matrix[row1][col2 + 1] -= 1;
    if (row2 + 1 < n)
        matrix[row2 + 1][col1] -= 1;
}

void printMatrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void testMatrixOperations(int n, int queries[][4], int num_queries) {
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)calloc(n, sizeof(int));
    }

    for (int i = 0; i < num_queries; i++) {
        int row1 = queries[i][0];
        int col1 = queries[i][1];
        int row2 = queries[i][2];
        int col2 = queries[i][3];
        addSubmatrix(matrix, row1, col1, row2, col2, n);
    }

    printf("Resulting Matrix:\n");
    printMatrix(matrix, n);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int n = 3;
    int queries[][4] = {{1, 1, 2, 2}, {0, 0, 1, 1}};
    int num_queries = sizeof(queries) / sizeof(queries[0]);

    testMatrixOperations(n, queries, num_queries);

    return 0;
}