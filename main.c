#include <stdio.h>

// Максимальное количество элементов в множестве
#define MAX_SIZE 10

// Структура для множества
typedef struct {
    int elements[MAX_SIZE];
    int size;
} Set;

// Функция для добавления элемента в множество
void addToSet(Set *set, int element) {
    if (set->size < MAX_SIZE) {
        set->elements[set->size++] = element;
    } else {
        printf("Ошибка: множество переполнено.\n");
    }
}

// Функция для удаления элемента из множества
void removeFromSet(Set *set, int element) {
    int i, found = 0;
    for (i = 0; i < set->size; ++i) {
        if (set->elements[i] == element) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (; i < set->size - 1; ++i) {
            set->elements[i] = set->elements[i + 1];
        }
        set->size--;
    }
}

// Функция для проверки, является ли элемент членом множества
int isMember(Set *set, int element) {
    int i;
    for (i = 0; i < set->size; ++i) {
        if (set->elements[i] == element) {
            return 1; // Элемент найден
        }
    }
    return 0; // Элемент не найден
}

// Функция для вычисления разности двух множеств
Set setDifference(Set *set1, Set *set2) {
    Set result = {{0}, 0};
    int i;
    for (i = 0; i < set1->size; ++i) {
        if (!isMember(set2, set1->elements[i])) {
            addToSet(&result, set1->elements[i]);
        }
    }
    return result;
}

// Функция для вычисления симметрической разности двух множеств
Set symmetricDifference(Set *set1, Set *set2) {
    Set result = setDifference(set1, set2);
    int i;
    for (i = 0; i < set2->size; ++i) {
        if (!isMember(set1, set2->elements[i])) {
            addToSet(&result, set2->elements[i]);
        }
    }
    return result;
}

int main() {
    // Определение множеств A, B и C
    Set A = {{1, 2, 3, 4, 8}, 5};
    Set B = {{2, 3, 8}, 3};
    Set C = {{3, 4, 5, 6, 7}, 5};

    // Вычисление D = A - (C ∆ B ◡ (C - A))
    Set CA = setDifference(&C, &A);
    Set CBA = symmetricDifference(&C, &B);
    Set D = setDifference(&A, &CBA);

    // Вывод результатов
    printf("D = {");
    for (int i = 0; i < D.size; ++i) {
        printf("%d", D.elements[i]);
        if (i < D.size - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    return 0;
}