#include <stdio.h>
#include <stdlib.h>

void filterNumbers(const char *inputFilename, const char *outputFilename, int N) {
    FILE *inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    int num;
    while (fscanf(inputFile, "%d", &num) == 1) {
        if (num < N) {
            fprintf(outputFile, "%d\n", num);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

void testFilterNumbers() {
    FILE *tempFile = fopen("temp_input.txt", "w");
    if (tempFile == NULL) {
        perror("Error creating temporary input file");
        exit(EXIT_FAILURE);
    }
    fprintf(tempFile, "5\n10\n3\n7\n2\n");
    fclose(tempFile);

    filterNumbers("temp_input.txt", "output.txt", 5);

    FILE *outputFile = fopen("output.txt", "r");
    if (outputFile == NULL) {
        perror("Error opening output file for testing");
        exit(EXIT_FAILURE);
    }
    int num;
    while (fscanf(outputFile, "%d", &num) == 1) {
        printf("%d ", num);
    }
    fclose(outputFile);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s input_file output_file N\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *inputFilename = argv[1];
    char *outputFilename = argv[2];
    int N = atoi(argv[3]);

    filterNumbers(inputFilename, outputFilename, N);

    testFilterNumbers();

    return EXIT_SUCCESS;
}