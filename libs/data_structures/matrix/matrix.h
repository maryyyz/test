//
// Created by mari on 22.03.24.
//

#ifndef COURSE_MATRIX_H
#define COURSE_MATRIX_H

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;
typedef struct position {
    int rowIndex;
    int colIndex;
} position;


#endif //COURSE_MATRIX_H
