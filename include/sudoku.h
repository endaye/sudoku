#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern unsigned short IMPOSSIBLE;
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;
extern int UNSOLVED;

/* 9*9 box */
typedef struct Box
{
    struct Box * next;

} Box;

/* every single square*/
typedef struct Square
{
    unsigned int number;

    /* A 9-bit vector to present the possible number could be fit in the square:
     * 000000000
     * 987654321
     * 0: could be the relative number
     * 1: cannot be that number */
    unsigned short code;
    Box * box;
    int row;
    int column;
} Square;

/* sudoku.c */
int ** createPuzzle();
void printPuzzle(Square ***);
Square *** setUpPuzzle(int ** puzzle);
void checkPuzzle(Square *** sudoku);

int updateSudoku(Square *** sudoku, int row, int column);

/* square.c */
int checkCode(Square * square);
int solveSquare(Square * square);

#endif