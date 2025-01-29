
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void fillBoard(char board[8][8]);
void displayBoard(char board[8][8]);

extern bool isCastlingLegal(char currentRow,char currentCol,char row,char col,char board[8][8]);

//global variable
extern int blackkingMoved  ;
extern int whitekingMoved  ;
extern int leftKing  ;
extern int rightKing  ;
extern int rightking ;
extern int leftking  ;
extern int turn ;


bool isCastlingLegal(char currentRow,char currentCol,char row,char col,char board[8][8])
{   //for checking rook being moved, used variable increment in ismovelegal function

    if(board[currentRow - 48][currentCol - 65] == 'K' ) //if king has moved, castling not alowed....must be checked for each user
    {
        if(whitekingMoved > 0)
        return 0;
    }
    else
    {
        if(blackkingMoved > 0)
        return 0;
    }

    if( col - currentCol  != 2 &&  col - currentCol  !=  -2) //castling moves
    {
        return 0;
    }

    if(col - currentCol == 2)
    {
        if(board[currentRow - 48][currentCol - 65] == 'K' )
        {
            if(board[0][7] != 'R')
            return 0;
            if(board[0][6] !=' ' || board[0][5] !=' ' )
            return 0;
            if(rightKing != 0)//increment variable if rook has moved
            return 0;

            board[0][7] = ' ';
            board[0][5] = 'R';
        }
        if(board[currentRow - 48][currentCol - 65] == 'k' )
        {
            if(board[7][7] != 'r')
            return 0;
            if(board[7][6] !=' ' || board[7][5] !=' ' )
            return 0;
            if(rightking != 0)
            return 0;

            board[7][7] = ' ';
            board[7][5] = 'r';
        }
    }

    
    if(col - currentCol == -2)
    {
        if(board[currentRow - 48][currentCol - 65] == 'K' )
        {
            if(board[0][0] != 'R')
            return 0;
            if(board[0][1] !=' ' || board[0][2] !=' ' || board[0][3] !=' ' )
            return 0;
            if(leftKing != 0)
            return 0;

            board[0][0] = ' ';
            board[0][3] = 'R';
        }
        if(board[currentRow - 48][currentCol - 65] == 'k' )
        {
            if(board[7][0] != 'r')
            return 0;
            if(board[7][1] !=' ' || board[7][2] !=' ' || board[7][3] !=' ' )
            return 0;
            if(leftking != 0)
            return 0;

            board[7][0] = ' ';
            board[7][3] = 'r';
        }
    }
    return 1;
}