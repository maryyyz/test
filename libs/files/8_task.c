#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int order;
    int **data;
} Matrix;

Matrix create_matrix(int order) {
    Matrix matrix;
    matrix.order = order;
    matrix.data = (int **)malloc(order * sizeof(int *));

    for (int i = 0; i < order; i++) {
        matrix.data[i] = (int *)malloc(order * sizeof(int));
    }

    return matrix;
}

void free_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->order; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
}

void generateTestFileForProcessFile(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error creating test file.\n");
        return;
    }

    srand(time(NULL));

    const int num_matrices = 3;

    for (int k = 0; k < num_matrices; k++) {
        int order = rand() % 4 + 2;

        fwrite(&order, sizeof(int), 1, file);

        Matrix matrix = create_matrix(order);

        for (int i = 0; i < order; i++) {
            for (int j = 0; j < order; j++) {
                matrix.data[i][j] = rand() % 21 - 10;
            }
        }

        for (int i = 0; i < order; i++) {
            fwrite(matrix.data[i], sizeof(int), order, file);
        }

        free_matrix(&matrix);
    }

    int end_marker = 0;
    fwrite(&end_marker, sizeof(int), 1, file);

    fclose(file);
}


int is_symmetric(const Matrix *matrix) {
    for (int i = 0; i < matrix->order; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix->data[i][j] != matrix->data[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

void transpose(Matrix *matrix) {
    for (int i = 0; i < matrix->order; i++) {
        for (int j = 0; j < i; j++) {
            int temp = matrix->data[i][j];
            matrix->data[i][j] = matrix->data[j][i];
            matrix->data[j][i] = temp;
        }
    }
}

void process_file(const char *filename) {
    FILE *file = fopen(filename, "rb+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (1) {
        int order;
        fread(&order, sizeof(int), 1, file);

        if (order == 0) {
            break;
        }

        Matrix matrix = create_matrix(order);

        for (int i = 0; i < order; i++) {
            fread(matrix.data[i], sizeof(int), order, file);
        }

        if (!is_symmetric(&matrix)) {
            transpose(&matrix);

            fseek(file, -order * order * sizeof(int), SEEK_CUR);

            fwrite(&order, sizeof(int), 1, file);

            for (int i = 0; i < order; i++) {
                fwrite(matrix.data[i], sizeof(int), order, file);
            }
        }

        free_matrix(&matrix);
    }

    fclose(file);
    printf("File processed successfully.\n");
}

void testProcessFile() {
    const char *filename = "matrices.bin";

    generateTestFileForProcessFile(filename);

    process_file(filename);
}

int main() {
    testProcessFile();
    return 0;
}