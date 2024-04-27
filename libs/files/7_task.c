#include <stdio.h>
#include <stdlib.h>

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

void process_file(const char *filename) {
    FILE *file = fopen(filename, "rb+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    int num_elements = file_size / sizeof(int);

    int *arr = (int *)malloc(num_elements * sizeof(int));

    fread(arr, sizeof(int), num_elements, file);

    qsort(arr, num_elements, sizeof(int), compare);

    move_positive_first(arr, num_elements);

    rewind(file);

    fwrite(arr, sizeof(int), num_elements, file);

    free(arr);
    fclose(file);

    printf("File processed successfully.\n");
}

void testProcessFile() {
    const char *filename = "numbers.bin";
    int test_data[] = {3, -1, 5, -2, 4, -3};
    int num_elements = sizeof(test_data) / sizeof(test_data[0]);

    FILE *test_file = fopen(filename, "wb");
    if (test_file == NULL) {
        printf("Error creating test file.\n");
        return;
    }

    fwrite(test_data, sizeof(int), num_elements, test_file);
    fclose(test_file);

    process_file(filename);
}

int main() {
    testProcessFile();
    return 0;
}