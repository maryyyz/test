# include "bitset.h"
# include <stdio.h>

bitset bitset_create(unsigned setMaxValue) {
    assert (setMaxValue < 32);
    return (bitset) {0, setMaxValue};
}


bool bitset_in(bitset set, unsigned int value) {
    return (set.values & (1u << value)) != 0;
}

bool bitset_isEqual(bitset set1, bitset set2) {
    return set1.values == set2.values && set1.maxValue == set2.maxValue;
}

bool bitset_isSubset(bitset subset, bitset set) {
    return (subset.values & set.values) == subset.values;
}

void bitset_insert(bitset *set, unsigned int value) {
    if (value <= set->maxValue) {
        set->values |= (1u << value);
    }
}

void bitset_deleteElement(bitset *set, unsigned int value) {
    if (value <= set->maxValue) {
        set->values &= ~(1u << value);
    }
}

bitset bitset_union(bitset set1, bitset set2) {
    bitset set3 = {set1.values | set2.values , set1.maxValue | set2.maxValue};
    return set3;
}

bitset bitset_intersection(bitset set1, bitset set2) {
    assert (set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & set2.values, set1.maxValue};
}

bitset bitset_difference(bitset set1, bitset set2) {
    bitset set3 = {set1.values & ~set2.values , set1.maxValue & ~set2.maxValue};
    return set3;
}


bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    bitset set3 = {set1.values ^ set2.values , set1.maxValue ^ set2.maxValue};
    return set3;
}

bitset bitset_complement(bitset set) {
    bitset result;
    result.values = ~(set.values) & ((1u << (set.maxValue + 1)) - 1);
    result.maxValue = set.maxValue;
    return result;
}

void bitset_print(bitset set) {
    printf("{ ");
    for (unsigned int i = 0; i <= set.maxValue; i++) {
        if (bitset_in(set, i)) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}
