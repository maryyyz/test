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
)

target_link_libraries(data_structures algorithms)