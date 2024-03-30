#include <stdio.h>
#include <stdlib.h>
#include "multidimensional_arrays.h"
#include "matrix.h"
#include <limits.h>
#include <math.h>

void swapRowsWithMinMax(matrix m) {
    int minRowIndex = 0;
    int maxRowIndex = 0;
    int minColIndex = 0;
    int maxColIndex = 0;
    int min = m.data[0][0];
    int max = m.data[0][0];

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.data[i][j] < min) {
                min = m.data[i][j];
                minRowIndex = i;
                minColIndex = j;
            }
            if (m.data[i][j] > max) {
                max = m.data[i][j];
                maxRowIndex = i;
                maxColIndex = j;
            }
        }
    }

    if (minRowIndex == maxRowIndex) {
        return;
    }

    swapRows(m, minRowIndex, maxRowIndex);
}

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

void sortRowsByMaxElement(matrix m) {
    int *maxElements = malloc(m.nRows * sizeof(int));
    for (int i = 0; i < m.nRows; i++) {
        maxElements[i] = getMax(m.data[i], m.nCols);
    }
    for (int i = 0; i < m.nRows - 1; i++) {
        for (int j = 0; j < m.nRows - i - 1; j++) {
            if (maxElements[j] > maxElements[j + 1]) {
                int *tempRow = m.data[j];
                m.data[j] = m.data[j + 1];
                m.data[j + 1] = tempRow;
                int tempMax = maxElements[j];
                maxElements[j] = maxElements[j + 1];
                maxElements[j + 1] = tempMax;
            }
        }
    }
    free(maxElements);
}

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

void sortColsByMinElement(matrix m) {
    int *minElements = malloc(m.nCols * sizeof(int));
    for (int j = 0; j < m.nCols; j++) {
        minElements[j] = getMin(&m.data[0][j], m.nRows);
    }
    for (int j = 0; j < m.nCols - 1; j++) {
        for (int k = 0; k < m.nCols - j - 1; k++) {
            if (minElements[k] > minElements[k + 1]) {
                for (int i = 0; i < m.nRows; i++) {
                    int temp = m.data[i][k];
                    m.data[i][k] = m.data[i][k + 1];
                    m.data[i][k + 1] = temp;
                }
                int tempMin = minElements[k];
                minElements[k] = minElements[k + 1];
                minElements[k + 1] = tempMin;
            }
        }
    }
    free(minElements);
}

matrix createMatrix(int size) {
    matrix m;
    m.size = size;
    m.data = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        m.data[i] = malloc(size * sizeof(int));
    }
    return m;
}


matrix mulMatrices(matrix m1, matrix m2) {
    matrix result = createMatrix(m1.size);
    for (int i = 0; i < m1.size; i++) {
        for (int j = 0; j < m1.size; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < m1.size; k++) {
                result.data[i][j] += m1.data[i][k] * m2.data[k][j];
            }
        }
    }
    return result;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    int symmetric = 1;
    for (int i = 0; i < m->size; i++) {
        for (int j = 0; j < m->size; j++) {
            if (m->data[i][j] != m->data[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if (!symmetric) {
            break;
        }
    }
    if (symmetric) {
        matrix squared = mulMatrices(*m, *m);
        freeMatrix(*m);
        *m = squared;
    }
}

void freeMatrix(matrix m) {
    for (int i = 0; i < m.size; i++) {
        free(m.data[i]);
    }
    free(m.data);
}

bool isUnique(long long *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                return false;
            }
        }
    }
    return true;
}

long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long rowSums[m.size];
    for (int i = 0; i < m.size; i++) {
        rowSums[i] = getSum(m.data[i], m.size);
    }
    if (isUnique(rowSums, m.size)) {
        for (int i = 0; i < m.size; i++) {
            for (int j = i + 1; j < m.size; j++) {
                int temp = m.data[i][j];
                m.data[i][j] = m.data[j][i];
                m.data[j][i] = temp;
            }
        }
        printf("Матрица успешно транспонирована:\n");
    } else {
        printf("Суммы элементов строк матрицы равны, транспонирование не выполняется.\n");
    }
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    if (m1.size != m2.size) {
        printf("Матрицы не квадратные или имеют разный размер.\n");
        return false;
    }

    matrix temp = createMatrix(m1.size);

    for (int i = 0; i < m1.size; i++) {
        for (int j = 0; j < m1.size; j++) {
            temp.data[i][j] = 0;
            for (int k = 0; k < m1.size; k++) {
                temp.data[i][j] += m1.data[i][k] * m2.data[k][j];
            }
        }
    }

    bool isIdentity = true;
    for (int i = 0; i < m1.size; i++) {
        for (int j = 0; j < m1.size; j++) {
            if (i == j && temp.data[i][j] != 1) {
                isIdentity = false;
                break;
            } else if (i != j && temp.data[i][j] != 0) {
                isIdentity = false;
                break;
            }
        }
        if (!isIdentity) {
            break;
        }
    }

    freeMatrix(temp);

    return isIdentity;
}

matrix createMatrixRec(int Rows, int Cols) {
    matrix m;
    m.nRows = Rows;
    m.nCols = Cols;
    m.data = malloc(Rows * sizeof(int *));
    for (int i = 0; i < Rows; i++) {
        m.data[i] = malloc(Cols * sizeof(int));
    }
    return m;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int n = m.nRows;
    int m_plus_n_minus_1 = m.nRows + m.nCols - 1;

    int *maxElements = malloc(m_plus_n_minus_1 * sizeof(int));
    for (int i = 0; i < m_plus_n_minus_1; i++) {
        maxElements[i] = INT_MIN;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m.nCols; j++) {
            int pseudoDiagonalIndex = i + j;
            if (m.data[i][j] > maxElements[pseudoDiagonalIndex]) {
                maxElements[pseudoDiagonalIndex] = m.data[i][j];
            }
        }
    }

    long long sum = 0;
    for (int i = 0; i < m_plus_n_minus_1; i++) {
        sum += maxElements[i];
    }

    free(maxElements);

    return sum;
}

int getMinInArea(matrix m, int startRow, int startCol, int endRow, int endCol) {
    int minElement = m.data[startRow][startCol];
    for (int i = startRow; i <= endRow; i++) {
        for (int j = startCol; j <= endCol; j++) {
            if (m.data[i][j] < minElement) {
                minElement = m.data[i][j];
            }
        }
    }
    return minElement;
}

float getDistance(int *a, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i] * a[i];
    }
    return sqrt(sum);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    for (int i = 1; i < m.nRows; i++) {
        int *currentRow = m.data[i];
        int j = i - 1;
        while (j >= 0 && criteria(m.data[j], m.nCols) > criteria(currentRow, m.nCols)) {
            m.data[j + 1] = m.data[j];
            j--;
        }
        m.data[j + 1] = currentRow;
    }
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}