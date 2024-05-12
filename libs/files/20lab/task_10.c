#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

volatile sig_atomic_t interrupted = 0;

void handleCtrlC(int sig) {
    interrupted = 1;
}

void displayFilePortions(const char *filename, int N) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    int lineCount = 0;
    while (fgets(line, sizeof(line), file) != NULL && !interrupted) {
        printf("%s", line);
        lineCount++;
        if (lineCount == N) {
            printf("\nPress Ctrl+C to continue...\n");
            lineCount = 0;
            while (!interrupted) {
            }
            interrupted = 0;
        }
    }

    fclose(file);
}

void testDisplayFilePortions(const char *filename, int N) {
    printf("Displaying file \"%s\" in portions of %d lines:\n", filename, N);
    displayFilePortions(filename, N);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s filename N\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    int N = atoi(argv[2]);

    signal(SIGINT, handleCtrlC);

    displayFilePortions(filename, N);

    testDisplayFilePortions(filename, N);

    return EXIT_SUCCESS;
}