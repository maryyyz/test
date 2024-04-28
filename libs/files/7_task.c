#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void move_positive_first(int *arr, int size) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        while (arr[left] > 0 && left < right) left++;
        while (arr[right] < 0 && left < right) right--;

        if (left < right) {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
}

void generateTestFileForProcessFile(const char *filename) {
    const int num_elements = 20;
    int *test_data = malloc(num_elements * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < num_elements; i++) {
        test_data[i] = rand() % 101 - 50;
    }

    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error creating test file.\n");
        free(test_data);
        return;
    }

    fwrite(test_data, sizeof(int), num_elements, file);
    fclose(file);

    free(test_data);
}

void process_file(const char *filename);

void testProcessFile() {
    const char *filename = "numbers.bin";

    generateTestFileForProcessFile(filename);

    process_file(filename);
}

int main() {
    testProcessFile();
    return 0;
}