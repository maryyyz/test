#include <stdio.h>
#include <string.h>

void generateTestFileForFilterWords(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file for writing\n");
        return;
    }

    fprintf(file, "apple banana orange pineapple grape\n");
    fprintf(file, "kiwi strawberry watermelon lemon\n");
    fprintf(file, "apple pie cherry apricot");

    fclose(file);
}

void generateTestFilesForFilterWords() {
    generateTestFileForFilterWords("input_words.txt");
}

void filter_words(const char *input_file, const char *output_file, const char *sequence) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");

    if (input == NULL || output == NULL) {
        printf("Error opening files.\n");
        return;
    }

    char word[100];

    while (fscanf(input, "%s", word) != EOF) {
        if (strstr(word, sequence) != NULL) {
            fprintf(output, "%s\n", word);
        }
    }

    printf("Filtered words saved to %s\n", output_file);

    fclose(input);
    fclose(output);
}

void test_filter_words() {
    const char *input_file = "input_words.txt";
    const char *output_file = "output_filtered_words.txt";
    const char *sequence = "apple";

    FILE *test_input = fopen(input_file, "w");
    if (test_input == NULL) {
        printf("Error creating test file.\n");
        return;
    }
    fprintf(test_input, "apple banana orange pineapple grape\n");
    fprintf(test_input, "kiwi strawberry watermelon lemon\n");
    fprintf(test_input, "apple pie cherry apricot");
    fclose(test_input);

    filter_words(input_file, output_file, sequence);

    FILE *test_output = fopen(output_file, "r");
    if (test_output == NULL) {
        printf("Error opening output file.\n");
        return;
    }

    char word[100];
    printf("Filtered words: ");
    while (fscanf(test_output, "%s", word) != EOF) {
        printf("%s ", word);
    }
    printf("\n");

    fclose(test_output);
}

int main() {
    generateTestFilesForFilterWords();
    test_filter_words();
    return 0;
}