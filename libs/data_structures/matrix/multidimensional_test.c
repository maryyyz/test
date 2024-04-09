#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "multidimensional_arrays.h"

void test_SwapRowsWithMinMax() {
    int data[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    matrix m;
    m.nRows = 3;
    m.nCols = 3;
    m.data = malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++) {
        m.data[i] = malloc(3 * sizeof(int));
        for (int j = 0; j < 3; j++) {
            m.data[i][j] = data[i][j];
        }
    }

    printf("Исходная матрица:\n");
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    swapRowsWithMinMax(m);

    printf("Матрица после обмена строк с минимальным и максимальным элементами:\n");
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    freeMatrix(m);
}

void test_SortRowsByMaxElement() {
    int data[3][3] = {{3, 2, 1}, {6, 5, 4}, {9, 8, 7}};
    matrix m;
    m.nRows = 3;
    m.nCols = 3;
    m.data = malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++) {
        m.data[i] = malloc(3 * sizeof(int));
        for (int j = 0; j < 3; j++) {
            m.data[i][j] = data[i][j];
        }
    }

    printf("Исходная матрица:\n");
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    sortRowsByMaxElement(m);

    printf("Матрица после сортировки строк по максимальному элементу:\n");
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    freeMatrix(m);
}

void test_SortColsByMinElement() {
    int data[3][3] = {{3, 2, 1}, {6, 5, 4}, {9, 8, 7}};
    matrix m;
    m.nRows = 3;
    m.nCols = 3;
    m.data = malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++) {
        m.data[i] = malloc(3 * sizeof(int));
        for (int j = 0; j < 3; j++) {
            m.data[i][j] = data[i][j];
        }
    }

    printf("Исходная матрица:\n");
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    sortColsByMinElement(m);

    printf("Матрица после сортировки столбцов по минимальному элементу:\n");
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    freeMatrix(m);
}

void test_MulMatrices() {
    int size = 3;
    matrix m1, m2;
    m1.size = m2.size = size;

    m1.data = malloc(size * sizeof(int *));
    m2.data = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        m1.data[i] = malloc(size * sizeof(int));
        m2.data[i] = malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            m1.data[i][j] = rand() % 10;
            m2.data[i][j] = rand() % 10;
        }
    }

    printf("Первая матрица:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", m1.data[i][j]);
        }
        printf("\n");
    }

    printf("Вторая матрица:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", m2.data[i][j]);
        }
        printf("\n");
    }

    matrix result = mulMatrices(m1, m2);

    printf("Результат умножения матриц:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", result.data[i][j]);
        }
        printf("\n");
    }

    freeMatrix(m1);
    freeMatrix(m2);
    freeMatrix(result);
}

void test_GetSquareOfMatrixIfSymmetric() {
    int size = 3;
    matrix m;
    m.size = size;

    m.data = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        m.data[i] = malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            m.data[i][j] = i + j;
        }
    }

    printf("Исходная матрица:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    getSquareOfMatrixIfSymmetric(&m);

    printf("Результат возведения в квадрат (если матрица была симметричной):\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    freeMatrix(m);
}

void test_TransposeIfMatrixHasNotEqualSumOfRows() {
    int size = 3;
    matrix m;
    m.size = size;

    m.data = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        m.data[i] = malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            m.data[i][j] = i + j;
        }
    }

    printf("Исходная матрица:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    transposeIfMatrixHasNotEqualSumOfRows(m);

    freeMatrix(m);
}

void test_IsMutuallyInverseMatrices() {
    int size = 3;
    matrix m1, m2;
    m1.size = m2.size = size;

    m1.data = malloc(size * sizeof(int *));
    m2.data = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        m1.data[i] = malloc(size * sizeof(int));
        m2.data[i] = malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            m1.data[i][j] = (i == j) ? 1 : 0;
            m2.data[i][j] = (i == j) ? 1 : -1;
        }
    }

    printf("Матрица m1:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", m1.data[i][j]);
        }
        printf("\n");
    }

    printf("Матрица m2:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", m2.data[i][j]);
        }
        printf("\n");
    }

    bool result = isMutuallyInverseMatrices(m1, m2);

    if (result) {
        printf("Матрицы являются взаимно обратными.\n");
    } else {
        printf("Матрицы не являются взаимно обратными.\n");
    }

    freeMatrix(m1);
    freeMatrix(m2);
}

void test_FindSumOfMaxesOfPseudoDiagonal() {
    int nRows = 3;
    int nCols = 3;
    matrix m;
    m.nRows = nRows;
    m.nCols = nCols;
    m.data = malloc(nRows * sizeof(int *));
    for (int i = 0; i < nRows; i++) {
        m.data[i] = malloc(nCols * sizeof(int));
    }

    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            m.data[i][j] = i + j;
        }
    }

    printf("Исходная матрица:\n");
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    long long sum = findSumOfMaxesOfPseudoDiagonal(m);
    printf("Сумма максимумов псевдодиагоналей: %lld\n", sum);

    freeMatrix(m);
}

void test_GetMinInArea() {
    int nRows = 3;
    int nCols = 3;
    matrix m;
    m.nRows = nRows;
    m.nCols = nCols;
    m.data = malloc(nRows * sizeof(int *));
    for (int i = 0; i < nRows; i++) {
        m.data[i] = malloc(nCols * sizeof(int));
    }

    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            m.data[i][j] = i + j;
        }
    }

    printf("Исходная матрица:\n");
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    int startRow = 0;
    int startCol = 0;
    int endRow = 1;
    int endCol = 1;

    int min = getMinInArea(m, startRow, startCol, endRow, endCol);
    printf("Минимальный элемент в области (%d, %d) - (%d, %d): %d\n", startRow, startCol, endRow, endCol, min);

    freeMatrix(m);
}

void test_InsertionSortRowsMatrixByRowCriteriaF() {
    int nRows = 3;
    int nCols = 3;
    matrix m;
    m.nRows = nRows;
    m.nCols = nCols;
    m.data = malloc(nRows * sizeof(int *));
    for (int i = 0; i < nRows; i++) {
        m.data[i] = malloc(nCols * sizeof(int));
    }

    m.data[0][0] = 3; m.data[0][1] = -1; m.data[0][2] = 4;
    m.data[1][0] = -2; m.data[1][1] = 5; m.data[1][2] = 6;
    m.data[2][0] = -9; m.data[2][1] = 8; m.data[2][2] = -7;

    printf("Исходная матрица:\n");
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    float (*countNegativeCriteria)(int *, int) = [](int *row, int nCols) {
        int count = 0;
        for (int i = 0; i < nCols; i++) {
            if (row[i] < 0) {
                count++;
            }
        }
        return (float)count;
    };

    insertionSortRowsMatrixByRowCriteriaF(m, countNegativeCriteria);

    printf("Отсортированная матрица по критерию количества отрицательных элементов в строке:\n");
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    freeMatrix(m);
}

void test_CountEqClassesByRowsSum() {
    int nRows = 3;
    int nCols = 3;
    matrix m;
    m.nRows = nRows;
    m.nCols = nCols;
    m.data = malloc(nRows * sizeof(int *));
    for (int i = 0; i < nRows; i++) {
        m.data[i] = malloc(nCols * sizeof(int));
    }

    m.data[0][0] = 1; m.data[0][1] = 2; m.data[0][2] = 3;
    m.data[1][0] = 4; m.data[1][1] = 5; m.data[1][2] = 6;
    m.data[2][0] = 7; m.data[2][1] = 8; m.data[2][2] = 9;

    printf("Исходная матрица:\n");
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    int uniqueClasses = countEqClassesByRowsSum(m);
    printf("Количество классов эквивалентности по суммам строк матрицы: %d\n", uniqueClasses);

    freeMatrix(m);
}

void test_GetNSpecialElement() {
    int nRows = 3;
    int nCols = 3;
    matrix m;
    m.nRows = nRows;
    m.nCols = nCols;
    m.data = malloc(nRows * sizeof(int *));
    for (int i = 0; i < nRows; i++) {
        m.data[i] = malloc(nCols * sizeof(int));
    }

    m.data[0][0] = 1; m.data[0][1] = 2; m.data[0][2] = 3;
    m.data[1][0] = 4; m.data[1][1] = 5; m.data[1][2] = 6;
    m.data[2][0] = 7; m.data[2][1] = 8; m.data[2][2] = 9;

    printf("Исходная матрица:\n");
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    int specialCount = getNSpecialElement(m);
    printf("Количество специальных элементов в матрице: %d\n", specialCount);

    freeMatrix(m);
}

void test_SwapPenultimateRow() {
    int size = 4;
    matrix m;
    m.size = size;
    m.data = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        m.data[i] = malloc(size * sizeof(int));
    }

    int value = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            m.data[i][j] = value++;
        }
    }

    printf("Исходная матрица:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    int minCol = 0;
    swapPenultimateRow(m, minCol);

    printf("Матрица после обмена строкой передпоследней строкой с элементами по заданному столбцу:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }

    freeMatrix(m);
}

void test_CountNonDescendingRowsMatrices() {
    int nMatrix = 3;
    matrix *matrices = malloc(nMatrix * sizeof(matrix));

    int rows = 3;
    int cols = 3;
    for (int i = 0; i < nMatrix; i++) {
        matrices[i].nRows = rows;
        matrices[i].nCols = cols;
        matrices[i].data = malloc(rows * sizeof(int *));
        for (int j = 0; j < rows; j++) {
            matrices[i].data[j] = malloc(cols * sizeof(int));
            for (int k = 0; k < cols; k++) {
                matrices[i].data[j][k] = j * cols + k + i;
            }
        }
    }

    printf("Исходные матрицы:\n");
    for (int i = 0; i < nMatrix; i++) {
        printf("Матрица %d:\n", i + 1);
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                printf("%d ", matrices[i].data[j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    int count = countNonDescendingRowsMatrices(matrices, nMatrix);
    printf("Количество матриц с невозрастающими строками: %d\n", count);

    for (int i = 0; i < nMatrix; i++) {
        freeMatrix(matrices[i]);
    }
    free(matrices);
}

void test_CountZeroRows() {
    int rows = 4;
    int cols = 3;
    matrix m;
    m.nRows = rows;
    m.nCols = cols;
    m.data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m.data[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            m.data[i][j] = i * cols + j;
            if (i == 2) {
                m.data[i][j] = 0;
            }
        }
    }

    printf("Исходная матрица:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int zeroRowCount = countZeroRows(m);
    printf("Количество строк с нулевыми значениями: %d\n", zeroRowCount);

    freeMatrix(m);
}

void test_GetNSpecialElement2() {
    int rows = 3;
    int cols = 3;
    matrix m;
    m.nRows = rows;
    m.nCols = cols;
    m.data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m.data[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            m.data[i][j] = i * cols + j;
        }
    }

    printf("Исходная матрица:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int nSpecialElements = getNSpecialElement2(m);
    printf("Количество 'специальных' элементов: %d\n", nSpecialElements);

    freeMatrix(m);
}

void test_GetVectorIndexWithMaxAngle() {
    int rows = 3;
    int cols = 3;
    matrix m;
    m.nRows = rows;
    m.nCols = cols;
    m.data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m.data[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            m.data[i][j] = i * cols + j;
        }
    }

    int b[3] = {1, 1, 1};

    printf("Исходная матрица:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int maxAngleIndex = getVectorIndexWithMaxAngle(m, b);
    printf("Индекс вектора с максимальным углом к заданному вектору: %d\n", maxAngleIndex);

    freeMatrix(m);
}

void test_GetSpecialScalarProduct() {
    int size = 3;
    matrix m;
    m.size = size;
    m.data = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        m.data[i] = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            m.data[i][j] = i * size + j + 1;
        }
    }

    printf("Исходная матрица:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int n = 1;
    long long specialScalarProduct = getSpecialScalarProduct(m, n);
    printf("Специальное скалярное произведение: %lld\n", specialScalarProduct);

    freeMatrix(m);
}

void test() {
    test_SwapRowsWithMinMax();
    test_SortRowsByMaxElement();
    test_SortColsByMinElement();
    test_MulMatrices();
    test_GetSquareOfMatrixIfSymmetric();
    test_TransposeIfMatrixHasNotEqualSumOfRows();
    test_IsMutuallyInverseMatrices();
    test_FindSumOfMaxesOfPseudoDiagonal();
    test_GetMinInArea();
    test_InsertionSortRowsMatrixByRowCriteriaF();
    test_CountEqClassesByRowsSum();
    test_GetNSpecialElement();
    test_SwapPenultimateRow();
    test_CountNonDescendingRowsMatrices();
    test_CountZeroRows();
    test_GetNSpecialElement2();
    test_GetVectorIndexWithMaxAngle();
    test_GetSpecialScalarProduct();
}

int main() {
    test();

    return 0;
}