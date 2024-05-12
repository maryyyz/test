#include <stdio.h>

#define ROWS 4
#define COLS 3

int getLiveNeighbors(int board[][COLS], int row, int col) {
    int liveNeighbors = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == row && j == col)) {
                liveNeighbors += board[i][j];
            }
        }
    }
    return liveNeighbors;
}

void updateCell(int board[][COLS], int row, int col) {
    int liveNeighbors = getLiveNeighbors(board, row, col);
    if (board[row][col] == 1) {
        if (liveNeighbors < 2 || liveNeighbors > 3) {
            board[row][col] = 0;
        }
    } else {
        if (liveNeighbors == 3) {
            board[row][col] = 1;
        }
    }
}

void gameOfLife(int board[][COLS]) {
    int nextBoard[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            nextBoard[i][j] = board[i][j];
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            updateCell(nextBoard, i, j);
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = nextBoard[i][j];
        }
    }
}

void printBoard(int board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void testGameOfLife() {
    int board[ROWS][COLS] = {
            {0, 1, 0},
            {0, 0, 1},
            {1, 1, 1},
            {0, 0, 0}
    };

    printf("Original Board:\n");
    printBoard(board);

    gameOfLife(board);

    printf("\nNext Generation Board:\n");
    printBoard(board);
}

int main() {
    testGameOfLife();
    return 0;
}