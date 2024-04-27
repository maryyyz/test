#include <stdio.h>
#include <string.h>

char* find_longest_word(const char *line) {
    char *longest_word = NULL;
    char *word = strtok((char*)line, " ");

    while (word != NULL) {
        if (longest_word == NULL || strlen(word) > strlen(longest_word)) {
            longest_word = word;
        }
        word = strtok(NULL, " ");
    }

    return longest_word;
}

void process_file(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");

    if (input == NULL || output == NULL) {
        printf("Error opening files.\n");
        return;
    }

    char line[1000];

    while (fgets(line, sizeof(line), input) != NULL) {
        char *longest_word = find_longest_word(line);
        if (longest_word != NULL) {
            fprintf(output, "%s\n", longest_word);
        }
    }

    printf("Processed file saved to %s\n", output_file);

    fclose(input);
    fclose(output);
}

void test_process_file() {
    const char *input_file = "input_text.txt";
    const char *output_file = "output_longest_words.txt";

    FILE *test_input = fopen(input_file, "w");
    if (test_input == NULL) {
        printf("Error creating test file.\n");
        return;
    }
    fprintf(test_input, "This is a test sentence.\n");
    fprintf(test_input, "Another sentence with longer words.\n");
    fprintf(test_input, "Short words.");
    fclose(test_input);

    process_file(input_file, output_file);
}

int main() {
    test_process_file();
    return 0;
}