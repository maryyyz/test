#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void generateTestFileForConvert(const char *filename, int count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file for writing\n");
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        double number = (double)(rand()) / RAND_MAX * 100.0;
        fprintf(file, "%.6f\n", number);
    }

    fclose(file);
}

void generateTestFilesForConvert() {
    generateTestFileForConvert("test_fixed.txt", 3);
}

void convertFixedToFloat(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Failed to open input file\n");
        return;
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Failed to open output file\n");
        fclose(inputFile);
        return;
    }

    double number;
    while (fscanf(inputFile, "%lf", &number) == 1) {
        fprintf(outputFile, "%.2f\n", number);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void testConvertFixedToFloat() {
    FILE *testFile = fopen("test_fixed.txt", "w");
    if (testFile == NULL) {
        printf("Failed to create test file\n");
        return;
    }
    fprintf(testFile, "3.14159\n2.71828\n0.123456\n");
    fclose(testFile);

    convertFixedToFloat("test_fixed.txt", "float_numbers.txt");

    FILE *floatFile = fopen("float_numbers.txt", "r");
    if (floatFile == NULL) {
        printf("Failed to open transformed file\n");
        return;
    }

    double number;
    printf("Converted numbers:\n");
    while (fscanf(floatFile, "%lf", &number) == 1) {
        printf("%.2f\n", number);
    }

    fclose(floatFile);
}

int main() {
    generateTestFilesForConvert();
    testConvertFixedToFloat();

    return 0;
}