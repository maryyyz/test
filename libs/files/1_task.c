#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateMatrix(int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file for writing\n");
        return;
    }

    fprintf(file, "%d\n", n);

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(file, "%d ", rand() % 10 + 1);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void generateTestFiles() {
    generateMatrix(3, "test_matrix.txt");
    generateMatrix(2, "test_matrix2.txt");
}

int** readMatrixFromFile(FILE *file, int *n) {
    if (fscanf(file, "%d", n) != 1) {
        printf("Failed to read matrix size\n");
        return NULL;
    }

    int **matrix = (int**)malloc(*n * sizeof(int*));
    if (matrix == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < *n; i++) {
        matrix[i] = (int*)malloc(*n * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed\n");
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
        for (int j = 0; j < *n; j++) {
            if (fscanf(file, "%d", &matrix[i][j]) != 1) {
                printf("Failed to read matrix element\n");
                for (int k = 0; k <= i; k++) {
                    free(matrix[k]);
                }
                free(matrix);
                return NULL;
            }
        }
    }

    return matrix;
}

void writeMatrixToFile(FILE *file, int **matrix, int n) {
    fprintf(file, "%d\n", n);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
}

void freeMatrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void transformMatrixInFile(const char *inputFileName, const char *outputFileName) {
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

    int n;
    while (fscanf(inputFile, "%d", &n) == 1) {
        int **matrix = readMatrixFromFile(inputFile, &n);
        if (matrix == NULL) {
            printf("Failed to read matrix from file\n");
            fclose(inputFile);
            fclose(outputFile);
            return;
        }
        writeMatrixToFile(outputFile, matrix, n);
        freeMatrix(matrix, n);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void testTransformMatrixInFile() {
    FILE *testFile = fopen("test_matrix.txt", "w");
    if (testFile == NULL) {
        printf("Failed to create test file\n");
        return;
    }
    fprintf(testFile, "3\n1 2 3\n4 5 6\n7 8 9\n");
    fprintf(testFile, "2\n1 2\n3 4\n");
    fclose(testFile);

    transformMatrixInFile("test_matrix.txt", "transformed_matrix.txt");

    FILE *transformedFile = fopen("transformed_matrix.txt", "r");
    if (transformedFile == NULL) {
        printf("Failed to open transformed file\n");
        return;
    }

    int n, element;
    fscanf(transformedFile, "%d", &n);
    printf("Transformed matrices:\n");
    printf("Matrix 1:\n");
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            fscanf(transformedFile, "%d", &element);
            printf("%d ", element);
        }
        printf("\n");
    }

    fscanf(transformedFile, "%d", &n);
    printf("Matrix 2:\n");
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            fscanf(transformedFile, "%d", &element);
            printf("%d ", element);
        }
        printf("\n");
    }

    fclose(transformedFile);
}

int main() {
    generateTestFiles();
    testTransformMatrixInFile();
    return 0;
}