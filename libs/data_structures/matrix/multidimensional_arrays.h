//
// Created by mari on 30.03.24.
//

#ifndef COURSE_MULTIDIMENSIONAL_ARRAYS_H
#define COURSE_MULTIDIMENSIONAL_ARRAYS_H

#endif //COURSE_MULTIDIMENSIONAL_ARRAYS_H

#include <stdbool.h>

typedef struct {
    int **data;
    int nRows;
    int nCols;
    int size;
} matrix;

//Фуекция находит индексы минимального и максимального элементов в матрице,
//а затем вызывает функцию swapRows, чтобы поменять местами строки с этими индексами.
void swapRowsWithMinMax(matrix m);

// Функция для нахождения максимального элемента в строке
int getMax(int *a, int n);

// Функция для сортировки строк матрицы по неубыванию наибольших элементов строк
void sortRowsByMaxElement(matrix m);

// Функция для нахождения минимального элемента в столбце
int getMin(int *a, int n);

// Функция для упорядочения столбцов матрицы по неубыванию минимальных элементов столбцов
void sortColsByMinElement(matrix m);

// Создание квадратной матрицы
matrix createMatrix(int size);

// Функция для перемножения двух матриц
matrix mulMatrices(matrix m1, matrix m2);

// Функция для проверки симметричности матрицы и возведения ее в квадрат, если она симметрична
void getSquareOfMatrixIfSymmetric(matrix *m);

// Освобождение памяти, выделенной для матрицы
void freeMatrix(matrix m);

// Функция для проверки, есть ли в массиве уникальные элементы
bool isUnique(long long *a, int n);

// Функция для вычисления суммы элементов массива
long long getSum(int *a, int n);

// Функция для транспонирования матрицы, если суммы элементов строк не равны
void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

// Функция для проверки, являются ли две матрицы взаимно обратными
bool isMutuallyInverseMatrices(matrix m1, matrix m2);

// Функция для создания прямоугольной матрицы
matrix createMatrixRec(int rows, int cols);

// Функция для поиска суммы максимальных элементов псевдодиагоналей матрицы
long long findSumOfMaxesOfPseudoDiagonal(matrix m);