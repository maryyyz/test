#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

// Создание вектора заданного размера
vector createVector(size_t n) {
    vector v;
    v.size = n;
    v.capacity = n;
    v.data = (int *)malloc(n * sizeof(int));
    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return v;
}

// Изменение размера выделенной под вектор памяти
void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        v->data = NULL;
    } else {
        v->data = (int *)realloc(v->data, newCapacity * sizeof(int));
        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }
    v->capacity = newCapacity;
    if (v->size > newCapacity) {
        v->size = newCapacity;
    }
}

// Очистка элементов вектора
void clear(vector *v) {
    v->size = 0;
}

// Освобождение памяти, выделенной под неиспользуемые элементы
void shrinkToFit(vector *v) {
    if (v->size < v->capacity) {
        v->data = (int *)realloc(v->data, v->size * sizeof(int));
        if (v->data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
        v->capacity = v->size;
    }
}

// Удаление вектора
void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

// Проверка, является ли вектор пустым
bool isEmpty(vector *v) {
    return v->size == 0;
}

// Проверка, является ли вектор полным
bool isFull(vector *v) {
    return v->size == v->capacity;
}

// Получение значения элемента вектора по индексу
int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

// Добавление элемента в конец вектора
void pushBack(vector *v, int x) {
    if (isFull(v)) {
        reserve(v, v->capacity * 2);
    }
    v->data[v->size] = x;
    v->size++;
}