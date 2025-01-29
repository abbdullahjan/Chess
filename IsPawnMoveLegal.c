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


bool isPawnMoveLegal(char currentRow,char currentCol,char row,char col,char board[8][8])
{
    //white piece
    if(board[currentRow-48][currentCol-65] == 'P' )
    {if(currentCol == col && (row != currentRow))
    {
        if((currentRow == row-1) && board[row-48][col-65] == ' ')
        {
            return 1;
        }
        else if((currentRow == row-2) && currentRow == '1' && board[row-48][col-65] == ' ' && board[row-49][col-65] == ' ' )//1 index is second row from downside
        {                                                  //two moves are allowed at first turn of pawn
            return 1;
        }
    }            
    else if(((currentCol == col-1) || (currentCol == col+1)) && (row != currentRow))//for capturing piece
    {
        if(board[row-48][col-65] != ' ' || (board[row-48][col-65] >= 'a' && board[row-48][col-65] < 'z') )
        {
            if(currentRow == row-1)
            {
                return 1;
            }
            
        }
    }
    }
    else
    {//black piece
        {if(currentCol == col && (row != currentRow))
        {
        if((currentRow == row+1) && board[row-48][col-65] == ' ')
            {
                return 1;
            }
        else if((currentRow == row+2) && currentRow == '6' && board[row-48][col-65] == ' ' && board[row-47][col-65] == ' ' )//1 index is second row from downside
            {
                return 1;
            }
        }            
        else if((currentCol == col-1) || (currentCol == col+1))//for capturing piece
        {
            if(board[row-48][col-65] != ' ')
            {
                if(currentRow == row+1)
                {
                    return 1;
                }
            }
        }
        }
    }


    return 0;
}
