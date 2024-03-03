#include "vector.h"
#include <assert.h>

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    int value = 42;
    pushBack(&v, &value);
    assert(v.size == 1);
    assert(*(int *)back(&v) == value);
}

void test_pushBack_fullVector() {
    vector v = createVector(1);
    int value1 = 42;
    int value2 = 24;
    pushBack(&v, &value1);
    pushBack(&v, &value2);
    assert(v.size == 2);
    assert(*(int *)back(&v) == value2);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    int value = 42;
    pushBack(&v, &value);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(3);
    int values[] = {1, 2, 3};
    for (size_t i = 0; i < 3; ++i) {
        setVectorValue(&v, i, &values[i]);
    }
    assert(*(int *)atVector(&v, 1) == values[1]);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(3);
    int values[] = {1, 2, 3};
    for (size_t i = 0; i < 3; ++i) {
        setVectorValue(&v, i, &values[i]);
    }
    assert(*(int *)atVector(&v, 2) == values[2]);
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    int value = 42;
    pushBack(&v, &value);
    assert(*(int *)back(&v) == value);
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    int value = 42;
    pushBack(&v, &value);
    assert(*(int *)front(&v) == value);
}

void test_all_functions() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test_all_functions();
    return 0;
}