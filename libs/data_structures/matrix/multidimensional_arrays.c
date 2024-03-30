#include <stdio.h>
#include <stdlib.h>
#include "multidimensional_arrays.h"
#include "matrix.h"

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