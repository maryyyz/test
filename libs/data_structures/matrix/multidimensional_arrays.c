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