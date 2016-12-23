#include <stdio.h>
#include <stdlib.h>

char POSSIBLE = 0x1FF;

/* 9*9 box */
typedef struct Box
{
    struct Box * next;

} Box;

/* every single square*/
typedef struct Square
{
    unsigned int number;

    /* A 9-bit binary code to present the possible number could be fit in the square:
     * 000000000
     * 987654321
     * 0: could be the relative number
     * 1: cannot be that number */
    char code;

    Box * box;
    int row;
    int column;
} Square;

int ** createPuzzle();
void printPuzzle(int **);
Square *** setUpPuzzle(int ** puzzle);
