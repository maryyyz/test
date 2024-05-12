#include <stdio.h>
#include <stdlib.h>

int countSubmatrices(int **matrix, int matrixSize, int *matrixColSize) {
    int m = matrixSize;
    int n = *matrixColSize;
    int count = 0;

    for (int i = 0; i < m; i++) {
        int *nums = (int *)malloc(n * sizeof(int));

        for (int j = 0; j < n; j++) {
            nums[j] = matrix[i][j];
        }

        for (int j = 1; j < n; j++) {
            if (nums[j] != 0) {
                nums[j] += nums[j - 1];
            }
        }

        for (int j = 0; j < n; j++) {
            int min = nums[j];
            for (int k = j; k < n; k++) {
                if (nums[k] < min) {
                    min = nums[k];
                }
                count += min;
            }
        }

        free(nums);
    }

    return count;
}

void testCountSubmatrices() {
    int matrix1[][3] = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
    int *matrixPtr1[3] = {matrix1[0], matrix1[1], matrix1[2]};
    int matrixSize1 = 3;
    int matrixColSize1 = 3;
    int result1 = countSubmatrices(matrixPtr1, matrixSize1, &matrixColSize1);
    printf("Input: [[1,0,1],[1,1,0],[1,1,0]]\nOutput: %d\n", result1);
}

int main() {
    testCountSubmatrices();
    return 0;
}