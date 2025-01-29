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


bool isCheckFromKing(char kingRow,char kingCol,char board[8][8])
{
    //check from king is going to be always an alert if wrong move is played 
    if(board[kingRow][kingCol] == 'K')
    {
        for(int i=1;i>=-1;i=i-2)//check rightUp and LeftDown
        {
            if((board[kingRow + i][kingCol + i] == 'k'))
            {
                if((kingRow + i) >= 0 && (kingRow + i) <8 && (kingCol + i) >=0 && (kingRow + i) < 8)
                return 1;
            }
        }
        for(int i=1;i>=-1;i=i-2)//check leftUp and rightDown
        {
            if((board[kingRow - i][kingCol + i] == 'k'))
            {
                if((kingRow + i) >= 0 && (kingRow + i) <8 && (kingCol + i) >=0 && (kingRow + i) < 8)
                return 1;
            }
        }
        for(int i=1;i>=-1;i=i-2)//check left and right
        {
            if((board[kingRow][kingCol + i] == 'k'))
            {
                if((kingRow + i) >= 0 && (kingRow + i) <8 && (kingCol + i) >=0 && (kingRow + i) < 8)
                return 1;
            }
        }
        for(int i=1;i>=-1;i=i-2)//check Up and down
        {
            if((board[kingRow + i][kingCol] == 'k'))
            {
                if((kingRow + i) >= 0 && (kingRow + i) <8 && (kingCol + i) >=0 && (kingRow + i) < 8)
                return 1;
            }
        }
    }
    else
    {
        for(int i=1;i>=-1;i=i-2)//check rightUp and LeftDown
        {
            if((board[kingRow + i][kingCol + i] == 'K'))
            {
                if((kingRow + i) >= 0 && (kingRow + i) <8 && (kingCol + i) >=0 && (kingRow + i) < 8)
                return 1;
            }
        }
        for(int i=1;i>=-1;i=i-2)//check leftUp and rightDown
        {
            if((board[kingRow - i][kingCol + i] == 'K'))
            {
                if((kingRow + i) >= 0 && (kingRow + i) <8 && (kingCol + i) >=0 && (kingRow + i) < 8)
                return 1;
            }
        }
        for(int i=1;i>=-1;i=i-2)//check left and right
        {
            if((board[kingRow][kingCol + i] == 'K'))
            {
                if((kingRow + i) >= 0 && (kingRow + i) <8 && (kingCol + i) >=0 && (kingRow + i) < 8)
                return 1;
            }
        }
        for(int i=1;i>=-1;i=i-2)//check Up and down
        {
            if((board[kingRow + i][kingCol] == 'K'))
            {
                if((kingRow + i) >= 0 && (kingRow + i) <8 && (kingCol + i) >=0 && (kingRow + i) < 8)
                return 1;
            }
        }
    }
    return 0;
}
