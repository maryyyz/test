//
// Created by mari on 06.04.24.
//

#ifndef COURSE_STRING__H
#define COURSE_STRING__H
#include <stdio.h>

//функция поиска длины строки
size_t stringLength(const char *str);

//возвращает количество символов в строке (не считая ноль-символ)
size_t my_strlen(const char *str);

//возвращает указатель на первый элемент с кодом ch, расположенным на ленте памяти между
//адресами begin и end не включая end
char* find(char *begin, char *end, int ch);

//возвращает указатель на первый символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом
char* findNonSpace(char *begin);

//возвращает указатель на первый пробельный символ,
// расположенный на ленте памяти начиная с адреса begin или на первый ноль-символ.
char* findSpace(char *begin);

//возвращает указатель на первый справа символ, отличный от пробельных,
//расположенный на ленте памяти, начиная с rbegin и заканчивая rend
char* findNonSpaceReverse(char *rbegin, const char *rend);

//возвращает указатель на первый пробельный символ справа, начиная с rbegin и заканчивая rend
char* findSpaceReverse(char *rbegin, const char *rend);

//возвращает отрицательное значение, если lhs располагается до rhs
//в лексикографическом порядке (как в словаре), значение 0, если lhs и rhs
//равны, иначе – положительное значение.
int my_strcmp(const char *lhs, const char *rhs);

//записывает по адресу beginDestination
//фрагмент памяти, начиная с адреса beginSource до endSource
char* copy(const char *beginSource, const char *endSource, char *beginDestination);

//записывает по адресу beginDestination элементы из фрагмента
// памяти начиная с beginSource pаканчивая endSource, удовлетворяющие функции-предикату
char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

// Функция-предикат для тестирования
int isAlpha(int c);

//записывает по адресу beginDestination элементы из фрагмента памяти начиная с rbeginSource
//заканчивая rendSource, удовлетворяющие функции-предикату
char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

#endif //COURSE_STRING__H
