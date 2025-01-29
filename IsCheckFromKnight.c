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


bool isCheckFromKnight(char kingRow,char kingCol,char board[8][8])
{   
    if(board[kingRow][kingCol] == 'K'){
    //there are 8 places from where rook can attack, looking for every situation
    if(board[kingRow + 1][kingCol + 2] == 'n')
    {
        if(kingRow+1 < 8 && kingCol+2 <8)
        {
            return 1;
        }
    }
    if(board[kingRow - 1][kingCol - 2] == 'n')
    {
        if(kingRow-1 >=0  && kingCol-2 >=0)
        {
            return 1;
        }
    }
    if(board[kingRow - 1][kingCol + 2] == 'n')
    {
        if(kingRow-1 >= 0 && kingCol+2 <8)
        {
            return 1;
        }
    }
    if(board[kingRow + 1][kingCol - 2] == 'n')
    {
        if(kingRow+1 < 8 && kingCol-2 >=0)
        {
            return 1;
        }
    }
    if(board[kingRow + 2][kingCol + 1] == 'n')
    {
        if(kingRow+2 < 8 && kingCol+2 <8)
        {
            return 1;
        }
    }
    if(board[kingRow - 2][kingCol - 1] == 'n')
    {
        if(kingRow-2 >=0  && kingCol-1 >=0)
        {
            return 1;
        }
    }
    if(board[kingRow - 2][kingCol + 1] == 'n')
    {
        if(kingRow-2 >= 0 && kingCol+1 <8)
        {
            return 1;
        }
    }
    if(board[kingRow + 2][kingCol - 1] == 'n')
    {
        if(kingRow+2 < 8 && kingCol-1 >=0)
        {
            return 1;
        }
    }
    return 0;
    }
    else
    {
    if(board[kingRow + 1][kingCol + 2] == 'N')
    {
        if(kingRow+1 < 8 && kingCol+2 <8)
        {
            return 1;
        }
    }
    if(board[kingRow - 1][kingCol - 2] == 'N')
    {
        if(kingRow-1 >=0  && kingCol-2 >=0)
        {
            return 1;
        }
    }
    if(board[kingRow - 1][kingCol + 2] == 'N')
    {
        if(kingRow-1 >= 0 && kingCol+2 <8)
        {
            return 1;
        }
    }
    if(board[kingRow + 1][kingCol - 2] == 'N')
    {
        if(kingRow+1 < 8 && kingCol-2 >=0)
        {
            return 1;
        }
    }
    if(board[kingRow + 2][kingCol + 1] == 'N')
    {
        if(kingRow+2 < 8 && kingCol+2 <8)
        {
            return 1;
        }
    }
    if(board[kingRow - 2][kingCol - 1] == 'N')
    {
        if(kingRow-2 >=0  && kingCol-1 >=0)
        {
            return 1;
        }
    }
    if(board[kingRow - 2][kingCol + 1] == 'N')
    {
        if(kingRow-2 >= 0 && kingCol+1 <8)
        {
            return 1;
        }
    }
    if(board[kingRow + 2][kingCol - 1] == 'N')
    {
        if(kingRow+2 < 8 && kingCol-1 >=0)
        {
            return 1;
        }
    }
    return 0;
    }
}

