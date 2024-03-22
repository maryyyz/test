#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int*) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);

    return (matrix){values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix*) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);

    return ms;
}

void freeMemMatrix(matrix *m) {
    if (m == NULL) {
        return;
    }

    for (int i = 0; i < m->nRows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    if (ms == NULL) {
        return;
    }

    for (int i = 0; i < nMatrices; i++) {
        freeMemMatrix(&ms[i]);
    }

    free(ms);
}

void inputMatrix(matrix *m) {
    printf("Введите количество строк матрицы: ");
    scanf("%d", &m->nRows);

    printf("Введите количество столбцов матрицы: ");
    scanf("%d", &m->nCols);

    m->data = (int*)malloc(m->nRows * m->nCols * sizeof(int));

    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < m->nRows; i++)
        for (int j = 0; j < m->nCols; j++) {
            printf("Элемент [%d][%d]: ", i, j);
            scanf("%d", &m->data[i * m->nCols + j]);
        }

}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        inputMatrix(&ms[i]);
    }
}

void outputMatrix(matrix m) {
    printf("Матрица %dx%d:\n", m.nRows, m.nCols);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf("%d ", m.data[i * m.nCols + j]);
        }
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        printf("Матрица %d:\n", i + 1);
        outputMatrix(ms[i]);
        printf("\n");
    }
}