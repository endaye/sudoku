#include "../include/sudoku.h"

Square *** setUpPuzzle(int ** puzzle)
{
    Square *** sudoku;
    int i, j;

    sudoku = (Square***)malloc(sizeof(Square**) * 9);

    /* loop through rows*/
    for (i = 0; i < SIZE_ROWS; ++i)
    {
        /* malloc space for each row */
        sudoku[i] = (Square**)malloc(sizeof(Square*) * 9);

        /* loop through columns */
        for (j = 0; j < SIZE_COLUMNS; ++j)
        {
            /* malloc space for each square */
            sudoku[i][j] = (Square*)malloc(sizeof(Square) * 9);

            /* assign number to sudoku adapter*/
            sudoku[i][j]->number = puzzle[i][j];

            /* assign row and column numbers to each square */
            sudoku[i][j]->row = i;
            sudoku[i][j]->column = j;

            /* if number is not zero, the square is not empty*/
            if (sudoku[i][j]->number != 0)
            {
                sudoku[i][j]->code = IMPOSSIBLE;
            }
            /* else the square is empty */
            else
            {
                sudoku[i][j]->code = 0x0;
            }
        }
    }

    /* loop through rows*/
    for (i = 0; i < SIZE_ROWS; ++i)
    {
        /* loop through columns */
        for (j = 0; j < SIZE_COLUMNS; ++j)
        {
            if (sudoku[i][j]->number != 0)
            {
                updateSudoku(sudoku, i, j);
                --UNSOLVED;
            }
        }
    }

    return sudoku;
}

/* update sudoku */
int updateSudoku(Square *** sudoku, int row, int column)
{
    int x;
    int number = sudoku[row][column]->number;
    for (x = 0; x < SIZE_ROWS; ++x)
    {
        (sudoku[x][column]->code) |= (1 << (number - 1));
    }

    for (x = 0; x < SIZE_COLUMNS; ++x)
    {
        (sudoku[row][x]->code) |= (1 << (number - 1));
    }

    return 1;
}

/* check puzzles */
void checkPuzzle(Square *** sudoku)
{
    int i, j;

    /* loop through rows*/
    for (i = 0; i < SIZE_ROWS; ++i)
    {
        /* loop through columns */
        for (j = 0; j < SIZE_COLUMNS; ++j)
        {
            if (checkCode(sudoku[i][j]) == 8)
            {
                solveSquare(sudoku[i][j]);
                updateSudoku(sudoku, i, j);
            }
        }
    }
}

/* create puzzles */
int **createPuzzle() {
    int **puzzle;
    int i, j;
    int array[9][9] = {0, 1, 9,     8, 0, 2,    0, 0, 0,
                       4, 7, 0,     6, 9, 0,    0, 0, 1,
                       0, 0, 0,     4, 0, 0,    0, 9, 0,

                       8, 9, 4,     5, 0, 7,    0, 0, 0,
                       0, 0, 0,     0, 0, 0,    0, 0, 0,
                       0, 0, 0,     2, 0, 1,    9, 5, 8,

                       0, 5, 0,     7, 0, 6,    0, 0, 0,
                       6, 0, 0,     3, 2, 8,    0, 7, 9,
                       0, 0, 0,     1, 0, 0,    8, 6, 0};

    puzzle = (int **) malloc(sizeof(int*) * 9);
    for (i = 0; i < SIZE_ROWS; ++i) {
        puzzle[i] = (int *) malloc(sizeof(int) * 9);
        for (j = 0; j < SIZE_COLUMNS; ++j) {
            puzzle[i][j] = array[i][j];
        }
    }
    return puzzle;
}

void printPuzzle(Square *** puzzle) {
    int i, j;

    printf("-------------------------\n");
    for (i = 0; i < SIZE_ROWS; ++i) {
        /* print each row */
        printf("| ");
        for (j = 0; j < SIZE_COLUMNS; ++j) {
            printf("%d ", puzzle[i][j]->number);
            if ((j + 1) % 3 == 0) {
                printf("| ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("-------------------------\n");
        }
    }
}


