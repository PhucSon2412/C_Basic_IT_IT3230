#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int matrix[9][9] = { 0 };

int check(int matrix[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        int rowSet[9] = {0};
        for (int j = 0; j < 9; j++)
        {
            if (rowSet[matrix[i][j] - 1] == 1) return 0;
            rowSet[matrix[i][j] - 1] = 1;
        }
    }
    for (int j = 0; j < 9; j++)
    {
        int colSet[9] = {0};
        for (int i = 0; i < 9; i++)
        {
            if (colSet[matrix[i][j] - 1] == 1) return 0;
            colSet[matrix[i][j] - 1] = 1;
        }
    }
    for (int startRow = 0; startRow < 9; startRow += 3) 
    {
        for (int startCol = 0; startCol < 9; startCol += 3)
        {
            int subSquareSet[9] = {0};
            for (int i = startRow; i < startRow + 3; i++) {
                for (int j = startCol; j < startCol + 3; j++)
                {
                    if (subSquareSet[matrix[i][j] - 1] == 1) return 0;
                    subSquareSet[matrix[i][j] - 1] = 1;
                }
            }
        }
    }
    return 1;
}

int main()
{
    int question, i, j;
    scanf("%i", &question);
    while (question--)
    {
        for ( i = 0 ; i < 9 ; i++ )
            for ( j = 0 ; j < 9 ; j++ )
                scanf("%i", &matrix[i][j]);

        printf("%i\n", check(matrix));
    }
}