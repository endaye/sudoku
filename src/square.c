//
// Created by yzhang on 12/24/2016.
//

#include "../include/sudoku.h"

/* 检查一个二进制数字里有多少个1 */
int checkCode(Square * square)
{
    int code = square->code;
    int count = 0;
    do
    {
        code = code & (code - 1);
        ++count;
    } while (code > 0);
    return count;
}

int solveSquare(Square * square)
{
    int x;

    for (x = 0; x < SIZE_ROWS; ++x)
    {
        if (!((square->code >> x) & 1))
        {
            square->number = x + 1;
            square->code |= (1 << x);
            --UNSOLVED;
        }
    }
    return 1;
}

