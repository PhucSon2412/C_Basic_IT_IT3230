#include <stdio.h>

#define SIZE 9

// Function to check if a given matrix is a valid Sudoku solution
int isValidSudoku(int matrix[SIZE][SIZE]) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        int rowSet[SIZE] = {0};
        for (int j = 0; j < SIZE; j++) {
            if (rowSet[matrix[i][j] - 1] == 1) {
                return 0; // Not a valid Sudoku
            }
            rowSet[matrix[i][j] - 1] = 1;
        }
    }

    // Check columns
    for (int j = 0; j < SIZE; j++) {
        int colSet[SIZE] = {0};
        for (int i = 0; i < SIZE; i++) {
            if (colSet[matrix[i][j] - 1] == 1) {
                return 0; // Not a valid Sudoku
            }
            colSet[matrix[i][j] - 1] = 1;
        }
    }

    // Check sub-squares
    for (int startRow = 0; startRow < SIZE; startRow += 3) {
        for (int startCol = 0; startCol < SIZE; startCol += 3) {
            int subSquareSet[SIZE] = {0};
            for (int i = startRow; i < startRow + 3; i++) {
                for (int j = startCol; j < startCol + 3; j++) {
                    if (subSquareSet[matrix[i][j] - 1] == 1) {
                        return 0; // Not a valid Sudoku
                    }
                    subSquareSet[matrix[i][j] - 1] = 1;
                }
            }
        }
    }

    return 1; // Valid Sudoku
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int matrix[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        int result = isValidSudoku(matrix);
        printf("%d\n", result);
    }

    return 0;
}
