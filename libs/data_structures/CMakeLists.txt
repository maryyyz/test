add_library(data_structures
        bitset/bitset.c
        unorderedset/unorderedset.h
        unorderedset/unorderedset.h
        unorderedset/unorderedset.c
        orderedset/orderedset.h
        orderedset/orderedset.c
        vector/vector.h
        vector/vector.c
        vectorvoid/vectorvoid.h
        vectorvoid/vectorvoid.c
        matrix/matrix.h
        matrix/matrix.c
        matrix/matrix_test.c
        matrix/multidimensional_arrays.h
        matrix/multidimensional_arrays.h
        matrix/multidimensional_arrays.c
        matrix/multidimensional_test.c
        string_/tasks/string_.h
        string_/stringTest.c
        string_/string_.c
        string_/tasks/task1.c
)

target_link_libraries(data_structures algorithms)