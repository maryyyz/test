//
// Created by mari on 06.04.24.
//

#ifndef COURSE_STRING__H
#define COURSE_STRING__H
#include <stdio.h>
#include <stdbool.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)
#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

char _stringBuffer[MAX_STRING_SIZE + 1];

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

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

// Функция вернёт значение 0, если слово не было считано, в противном
// случае будет возвращено значение 1 и в переменную word типа WordDescriptor
// будут записаны позиции начала слова, и первого символа после конца слова
int getWord(char *beginSearch, WordDescriptor *word) ;

// Функция начинает считывание с переданного указателя s и
// перемещается по строке до тех пор, пока не достигнет символа завершающего нуля.
// Возвращает указатель на предыдущий символ, который является последним символом строки перед '\0'.
char* getEndOfString(char* s) ;

// Функция для считывания слова с конца строки
bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) ;

// Выполняет операцию сортировки символов в строке,
// перемещая цифры в начало строки
void digitToStart(WordDescriptor word) ;

// Функция для тестирования
void assertString(const char *expected, char *got,char const *fileName, char const *funcName, int line) ;

#endif //COURSE_STRING__H
