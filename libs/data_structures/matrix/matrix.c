#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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


void swapRows(matrix m, int i1, int i2) {
    assert(i1 >= 0 && i1 < m.nRows);
    assert(i2 >= 0 && i2 < m.nRows);

    if (i1 == i2) {
        return;
    }

    for (int j = 0; j < m.nCols; j++) {
        int *temp = m.data[i1 * m.nCols + j];
        m.data[i1 * m.nCols + j] = m.data[i2 * m.nCols + j];
        m.data[i2 * m.nCols + j] = temp;
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int*, int)) {
    int *criteriaValues = (int*)malloc(m.nRows * sizeof(int));

    for (int i = 0; i < m.nRows; i++) {
        int rowSum = 0;
        for (int j = 0; j < m.nCols; j++) {
            rowSum += *m.data[i * m.nCols + j];
        }
        criteriaValues[i] = criteria(&m.data[i * m.nCols], m.nCols);
    }

    for (int i = 1; i < m.nRows; i++) {
        int key = criteriaValues[i];
        int *keyRow = m.data[i * m.nCols];
        int j = i - 1;

        while (j >= 0 && criteriaValues[j] > key) {
            criteriaValues[j + 1] = criteriaValues[j];
            for (int k = 0; k < m.nCols; k++) {
                m.data[(j + 1) * m.nCols + k] = m.data[j * m.nCols + k];
            }
            j--;
        }

        criteriaValues[j + 1] = key;
        for (int k = 0; k < m.nCols; k++) {
            m.data[(j + 1) * m.nCols + k] = keyRow;
        }
    }

    free(criteriaValues);
}

void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int*, int)) {
    for (int i = 0; i < m.nCols; i++) {
        for (int j = i + 1; j < m.nCols; j++) {
            int sum1 = 0;
            int sum2 = 0;

            for (int k = 0; k < m.nRows; k++) {
                sum1 += *m.data[k * m.nCols + i];
                sum2 += *m.data[k * m.nCols + j];
            }

            if (criteria(&sum2, 1) < criteria(&sum1, 1)) {
                for (int k = 0; k < m.nRows; k++) {
                    int *temp = m.data[k * m.nCols + i];
                    m.data[k * m.nCols + i] = m.data[k * m.nCols + j];
                    m.data[k * m.nCols + j] = temp;
                }
            }
        }
    }
}


