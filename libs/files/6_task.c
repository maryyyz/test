#include <stdio.h>

typedef struct {
    int exponent;
    float coefficient;
} Polynomial;

float power(float x, int n) {
    float result = 1.0;

    for (int i = 0; i < n; i++) {
        result *= x;
    }

    return result;
}

void remove_polynomials_with_root(const char *filename, float x) {
    FILE *file = fopen(filename, "rb+");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Polynomial poly;

    while (fread(&poly, sizeof(Polynomial), 1, file) == 1) {
        if (poly.coefficient != 0 && poly.exponent > 0 && poly.coefficient * power(x, poly.exponent) == 0) {
            fseek(file, -sizeof(Polynomial), SEEK_CUR);
            Polynomial empty_poly = {0, 0};
            fwrite(&empty_poly, sizeof(Polynomial), 1, file);
            fflush(file);
        }
    }

    printf("Polynomials with root %f removed from file.\n", x);

    fclose(file);
}

void testRemovePolynomialsWithRoot() {
    const char *filename = "polynomials.bin";
    const float root = 2.0f;

    FILE *test_file = fopen(filename, "wb");
    if (test_file == NULL) {
        printf("Error creating test file.\n");
        return;
    }

    Polynomial polys[] = {
            {3, 2.0},
            {2, 1.0},
            {1, -3.0},
            {0, 4.0}
    };

    fwrite(polys, sizeof(Polynomial), sizeof(polys) / sizeof(polys[0]), test_file);
    fclose(test_file);

    remove_polynomials_with_root(filename, root);
}

int main() {
    testRemovePolynomialsWithRoot();
    return 0;
}