#include "sudoku.h"

//main function
int main() 
{
	int ** puzzle;
	puzzle = createPuzzle();
	printPuzzle(puzzle);
	return 0;
}

