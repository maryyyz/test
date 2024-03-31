//
// Created by mari on 30.03.24.
//

#ifndef COURSE_MULTIDIMENSIONAL_ARRAYS_H
#define COURSE_MULTIDIMENSIONAL_ARRAYS_H


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

// Функция для нахождения минимального элемента в области матрицы
int getMinInArea(matrix m, int startRow, int startCol, int endRow, int endCol);

// Функция для вычисления расстояния от точки до начала координат в многомерном пространстве
float getDistance(int *a, int n);

// Функция сортировки вставками для матрицы с использованием критерия criteria
void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int));

// Функция для сортировки массива точек по неубыванию их расстояний до начала координат
void sortByDistances(matrix m);

// Функция для сравнения двух элементов типа long long (используется при сортировке)
int cmp_long_long(const void *pa, const void *pb);

// Функция для подсчета количества уникальных элементов в отсортированном массиве
int countNUnique(long long *a, int n);

// Функция для подсчета количества классов эквивалентных строк матрицы
int countEqClassesByRowsSum(matrix m);

// Функция для вычисления количества "особых" элементов в матрице
int getNSpecialElement(matrix m);

// Функция для нахождения первого столбца с минимальным элементом
int getLeftMin(matrix m);

// Функция для обмена предпоследней строки с первым столбцом, содержащим минимальный элемент
void swapPenultimateRow(matrix m, int minCol);

// Функция для проверки, упорядочены ли элементы массива по неубыванию
bool isNonDescendingSorted(int *a, int n);

// Функция для проверки, упорядочены ли строки матрицы по неубыванию
bool hasAllNonDescendingRows(matrix m);

// Функция для подсчета количества матриц с упорядоченными по неубыванию строками
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix);

// Функция для подсчета количества элементов в массиве, равных заданному значению
int countValues(const int *a, int n, int value);

// Функция для подсчета количества нулевых строк в матрице
int countZeroRows(matrix m);

// Функция для вывода матриц с наибольшим числом нулевых строк
void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix);

// Функция для вычисления нормы матрицы (максимум абсолютных значений её элементов)
int matrixNorm(matrix m);

// Функция для поиска матрицы с наименьшей нормой в массиве и вывода её на экран
void printMatrixWithMinNorm(matrix *matrices, int n);

// Функция для нахождения минимума из двух чисел
int min2(int a, int b);

// Функция для определения количества "особых" элементов в матрице
int getNSpecialElement2(matrix m);

// Функция для вычисления скалярного произведения двух векторов
double getScalarProduct(int *a, int *b, int n);

// Функция для вычисления длины вектора
double getVectorLength(int *a, int n);

// Функция для вычисления косинуса угла между двумя векторами
double getCosine(int *a, int *b, int n);

// Функция для определения индекса вектора из матрицы, образующего максимальный угол с данным вектором
int getVectorIndexWithMaxAngle(matrix m, int *b);

// Функция для вычисления скалярного произведения строки на столбец
long long getScalarProductRowAndCol(matrix m, int i, int j);

// Функция для нахождения скалярного произведения строки с наибольшим элементом на столбец с наименьшим элементом
long long getSpecialScalarProduct(matrix m, int n);

#endif //COURSE_MULTIDIMENSIONAL_ARRAYS_H