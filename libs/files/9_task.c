#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct {
    char full_name[MAX_NAME_LENGTH];
    int best_result;
} Athlete;

Athlete* read_athletes(const char *filename, int *num_athletes) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    *num_athletes = file_size / sizeof(Athlete);
    fseek(file, 0, SEEK_SET);

    Athlete *athletes = (Athlete *)malloc((*num_athletes) * sizeof(Athlete));

    fread(athletes, sizeof(Athlete), *num_athletes, file);

    fclose(file);
    return athletes;
}

int compare_athletes(const void *a, const void *b) {
    const Athlete *athlete_a = (const Athlete *)a;
    const Athlete *athlete_b = (const Athlete *)b;

    if (athlete_a->best_result < athlete_b->best_result) {
        return 1;
    } else if (athlete_a->best_result > athlete_b->best_result) {
        return -1;
    } else {
        return 0;
    }
}

void sort_athletes(Athlete *athletes, int num_athletes) {
    qsort(athletes, num_athletes, sizeof(Athlete), compare_athletes);
}


void write_top_athletes(const char *filename, Athlete *athletes, int num_athletes, int n) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fwrite(athletes, sizeof(Athlete), n, file);

    fclose(file);
    printf("Top %d athletes saved to file successfully.\n", n);
}

void testProcessFile() {
    const char *filename = "athletes.bin";
    int num_athletes = 5;
    Athlete test_data[] = {
            {"John Doe", 100},
            {"Jane Smith", 150},
            {"Michael Johnson", 120},
            {"Emma Lee", 90},
            {"Chris Brown", 110}
    };

    FILE *test_file = fopen(filename, "wb");
    if (test_file == NULL) {
        printf("Error creating test file.\n");
        return;
    }

    fwrite(test_data, sizeof(Athlete), num_athletes, test_file);
    fclose(test_file);

    int num_athletes_read;
    Athlete *athletes = read_athletes(filename, &num_athletes_read);

    if (athletes == NULL) {
        printf("Error reading athletes from file.\n");
        return;
    }

    sort_athletes(athletes, num_athletes_read);

    int n = 3;
    write_top_athletes("top_athletes.bin", athletes, num_athletes_read, n);

    free(athletes);
}

int main() {
    testProcessFile();
    return 0;
}