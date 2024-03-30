//
// Created by mari on 30.03.24.
//

#ifndef COURSE_MULTIDIMENSIONAL_ARRAYS_H
#define COURSE_MULTIDIMENSIONAL_ARRAYS_H

#endif //COURSE_MULTIDIMENSIONAL_ARRAYS_H

typedef struct {
    int **data;
    int nRows;
    int nCols;
} matrix;

//Фуекция находит индексы минимального и максимального элементов в матрице,
//а затем вызывает функцию swapRows, чтобы поменять местами строки с этими индексами.
void swapRowsWithMinMax(matrix m);

