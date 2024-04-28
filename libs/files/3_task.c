#include <stdio.h>

void generateTestFileForExpression(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file for writing\n");
        return;
    }

    fprintf(file, "5 + 3 * 2\n");
    fprintf(file, "10 - 2 * 3\n");
    fprintf(file, "6 * 4 + 2\n");

    fclose(file);
}

void generateTestFilesForExpression() {
    generateTestFileForExpression("test_expression.txt");
}

int calculateExpression(const char *fileName) {
    FILE *file = fopen(fileName, "r+");
    if (file == NULL) {
        printf("Failed to open file\n");
        return 0;
    }

    char operator1, operator2;
    int operand1, operand2, result;

    fscanf(file, "%d %c", &operand1, &operator1);
    fscanf(file, "%d %c", &operand2, &operator2);

    if (operator1 == '+') {
        if (operator2 == '+') {
            result = operand1 + operand2;
        } else if (operator2 == '-') {
            result = operand1 + operand2;
        } else if (operator2 == '*') {
            result = operand1 * operand2;
        } else {
            printf("Unsupported operator: %c\n", operator2);
            fclose(file);
            return 0;
        }
    } else if (operator1 == '-') {
        if (operator2 == '+') {
            result = operand1 - operand2;
        } else if (operator2 == '-') {
            result = operand1 - operand2;
        } else if (operator2 == '*') {
            result = operand1 * operand2;
        } else {
            printf("Unsupported operator: %c\n", operator2);
            fclose(file);
            return 0;
        }
    } else if (operator1 == '*') {
        if (operator2 == '+') {
            result = operand1 * operand2;
        } else if (operator2 == '-') {
            result = operand1 * operand2;
        } else if (operator2 == '*') {
            result = operand1 * operand2;
        } else {
            printf("Unsupported operator: %c\n", operator2);
            fclose(file);
            return 0;
        }
    } else {
        printf("Unsupported operator: %c\n", operator1);
        fclose(file);
        return 0;
    }

    fseek(file, 0, SEEK_END);
    fprintf(file, " = %d\n", result);

    fclose(file);
    return result;
}

void testCalculateExpression() {
    FILE *testFile = fopen("test_expression.txt", "w");
    if (testFile == NULL) {
        printf("Failed to create test file\n");
        return;
    }
    fprintf(testFile, "5 + 3 * 2\n");
    fclose(testFile);

    int result = calculateExpression("test_expression.txt");

    if (result != 11) {
        printf("Test failed: expected result 11, got %d\n", result);
    } else {
        printf("Test passed: result is 11\n");
    }
}

int main() {
    generateTestFilesForExpression();
    testCalculateExpression();

    return 0;
}