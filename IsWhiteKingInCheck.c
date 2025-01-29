//SP24-BCS-142      ABDULLAH JAN
//SP24-BCS-174      M.MUSTAFA

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


extern void fillBoard(char board[8][8]);
extern void displayBoard(char board[8][8]);
extern bool IsMoveLegal(char currentRow,char currentCol,char row,char col,char currentLocation[8][8]);
extern bool isPawnMoveLegal(char currentRow,char currentCol,char row,char col,char board[8][8]);
extern bool isRookMoveLegal(char currentRow,char currentCol,char row,char col,char board[8][8]);
extern bool isBishopMoveLegal(char currentRow,char currentCol,char row,char col,char board[8][8]);
extern bool isQueenMoveLegal(char currentRow,char currentCol,char row,char col,char board[8][8]);
extern bool isKnightMoveLegal(char currentRow,char currentCol,char row,char col,char board[8][8]);
extern bool isKingMoveLegal(char currentRow,char currentCol,char row,char col,char board[8][8]);
extern void PawnPromotion(char currentRow,char currentCol,char row,char col,char board[8][8]);
extern bool isWhiteKingInCheck(char board[8][8]);
extern bool isBlackKingInCheck(char board[8][8]);
extern bool isCheckFromRook(char kingRow,char kingCol,char board[8][8]);
extern bool isCheckFromBishop(char kingRow,char kingCol,char board[8][8]);
extern bool isCheckFromKnight(char kingRow,char kingCol,char board[8][8]);
extern bool isCheckFromPawn(char kingRow,char kingCol,char board[8][8]);
extern bool isCheckFromKing(char kingRow,char kingCol,char board[8][8]);
extern bool isCheckMate(char board[8][8]);
extern bool PieceAroundKingInCheck(char kingRow,char kingCol,char board[8][8]);


bool isWhiteKingInCheck(char board[8][8])
{
    //we will move from every path to king by every piece of the opponent,
    //we will check staright line from king to end of board in every direction which will check for rook and queen
    //we will check diagonal line from king to end of board in every direction which will check for bishop and queen

    //first check location of White King
    int kingRow,kingCol;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(board[i][j] == 'K')
            {
                kingRow = i;
                kingCol = j;
            }
        }
    }
    
    if(isCheckFromRook(kingRow,kingCol,board))
    {
        return 1;
    }
    if(isCheckFromBishop(kingRow,kingCol,board))
    {
        return 1;
    }
    if(isCheckFromKnight(kingRow,kingCol,board))
    {
        return 1;
    }
    if(isCheckFromPawn(kingRow,kingCol,board))
    {
        return 1;
    }
    if(isCheckFromKing(kingRow,kingCol,board))
    {
        return 1;
    }

    return 0;
}
