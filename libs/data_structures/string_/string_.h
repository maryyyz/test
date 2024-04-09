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

#endif //COURSE_STRING__H
