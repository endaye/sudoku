#include "../include/sudoku.h"

unsigned short IMPOSSIBLE = 0x1FF;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;
int UNSOLVED = 81;

//main function
int main() 
{
	int ** puzzle;
	Square *** sudoku;
	puzzle = createPuzzle();
	sudoku = setUpPuzzle(puzzle);

    printPuzzle(sudoku);

    checkPuzzle(sudoku);

    printf("\n");
    printPuzzle(sudoku);
	return 0;
}

