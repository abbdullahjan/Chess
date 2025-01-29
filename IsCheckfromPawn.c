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

bool isCheckFromPawn(char kingRow,char kingCol,char board[8][8])
{
    if(board[kingRow][kingCol] == 'K')
    {
        if(board[kingRow + 1][kingCol-1] == 'p')
        {
            if((kingCol+1 >= 0) && (kingRow + 1) <8)
            return 1;
        }
        if(board[kingRow + 1][kingCol+1] == 'p')
        {
            if((kingCol+1 < 8) && (kingRow + 1) <8) 
            return 1;
        }
    }
    else
    {
        if(board[kingRow - 1][kingCol-1] == 'P')
        {
            if((kingCol+1 >= 0) && (kingRow - 1) <8)
            return 1;
        }
        if(board[kingRow - 1][kingCol+1] == 'P')
        {
            if((kingCol+1 < 8) && (kingRow - 1) <8) 
            return 1;
        }
    
    }
    return 0;
}
