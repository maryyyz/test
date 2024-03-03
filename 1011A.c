#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char s[51]; // Массив для ступеней, +1 для нуль-терминатора
    scanf("%s", s);

    // Сортируем строку для упорядочивания ступеней по весу
    qsort(s, n, sizeof(char), (int(*)(const void*, const void*)) strcmp);

    int total_weight = 0; // Суммарный вес ракеты
    char last_step = 'a' - 2; // Последняя добавленная ступень, инициализируем так, чтобы можно было добавить 'a'
    int used_steps = 0; // Количество добавленных ступеней

    for (int i = 0; i < n && used_steps < k; i++) {
        if (s[i] - last_step >= 2) { // Проверяем условие расстояния между ступенями
            total_weight += s[i] - 'a' + 1; // Добавляем вес текущей ступени
            last_step = s[i]; // Обновляем последнюю добавленную ступень
            used_steps++; // Увеличиваем количество использованных ступеней
        }
    }

    if (used_steps == k) {
        printf("%d\n", total_weight); // Выводим суммарный вес ракеты
    } else {
        printf("-1\n"); // Ни одной ракеты построить нельзя
    }

    return 0;
}