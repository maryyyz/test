
#ifndef COURSE_MATRIX_H
#define COURSE_MATRIX_H

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
    int **data;
} matrix;
typedef struct position {
    int rowIndex;
    int colIndex;
} position;


//размещает в динамической памяти матрицу размером nRows на nCols. Возвращает матрицу.
matrix getMemMatrix(int nRows, int nCols);

//размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols. Возвращает указатель на нулевую матрицу.
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);


#endif //COURSE_MATRIX_H
