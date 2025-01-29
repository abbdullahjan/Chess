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

bool isCheckFromRook(char kingRow,char kingCol,char board[8][8])
{

    //check for threat upward
    if(board[kingRow][kingCol] == 'K') //need to differentiate enemy pieces by knowing current pieces
    {
    for(int i=kingRow + 1;i<8;i++)
    {
        if((board[i][kingCol] >= 'A') && (board[i][kingCol] <= 'Z'))
        {
            break;
        }
        else if((board[i][kingCol] == 'r') || (board[i][kingCol] == 'q'))
        {
            return 1;
        }
        else if((board[i][kingCol] == ' '))//to protect 'space' from else statement
        {}
        else
        {
            break;
        }
    }
    //check for threat downward
    for(int i=kingRow - 1;i>=0;i--)
    {
        if((board[i][kingCol] >= 'A') && (board[i][kingCol] <= 'Z'))
        {
            break;
        }
        else if((board[i][kingCol] == 'r') || (board[i][kingCol] == 'q'))
        {
            return 1;
        }
        else if((board[i][kingCol] == ' '))//to protect 'space' from else statement
        {}
        else
        {
            break;
        }
    
    }
    //check for threat on right
    for(int i=kingCol + 1;i<8;i++)
    {
        if((board[kingRow][i] >= 'A') && (board[kingRow][i] <= 'Z'))
        {
            break;
        }
        else if((board[kingRow][i] == 'r') || (board[kingRow][i] == 'q'))
        {
            return 1;
        }
        else if((board[kingRow][i] == ' '))//to protect 'space' from else statement
        {}
        else
        {
            break;
        }
    
    }
    for(int i=kingCol - 1;i>=0;i--)
    {
        if((board[kingRow][i] >= 'A') && (board[kingRow][i] <= 'Z'))
        {
            break;
        }
        else if((board[kingRow][i] == 'r') || (board[kingRow][i] == 'q'))
        {
            return 1;
        }
        else if((board[kingRow][i] == ' '))//to protect 'space' from else statement
        {}
        else
        {
            break;
        }
    
    }
    return 0;
    }
    else//Black's Turn
    {
    for(int i=kingRow + 1;i<8;i++)
    {
        if((board[i][kingCol] >= 'a') && (board[i][kingCol] <= 'z'))
        {
            break;
        }
        else if((board[i][kingCol] == 'R') || (board[i][kingCol] == 'Q'))
        {
            return 1;
        }
        else if((board[i][kingCol] == ' '))//to protect 'space' from else statement
        {}
        else
        {
            break;
        }
    }
    //check for threat downward
    for(int i=kingRow - 1;i>=0;i--)
    {
        if((board[i][kingCol] >= 'a') && (board[i][kingCol] <= 'z'))
        {
            break;
        }
        else if((board[i][kingCol] == 'R') || (board[i][kingCol] == 'Q'))
        {
            return 1;
        }
        else if((board[i][kingCol] == ' '))
        {}
        else
        {
            break;
        }
    
    }
    //check for threat on right
    for(int i=kingCol + 1;i<8;i++)
    {
        if((board[kingRow][i] >= 'a') && (board[kingRow][i] <= 'z'))
        {
            break;
        }
        else if((board[kingRow][i] == 'R') || (board[kingRow][i] == 'Q'))
        {
            return 1;
        }
        else if((board[kingRow][i] == ' '))
        {}
        else
        {
            break;
        }
    
    }
    for(int i=kingCol - 1;i>=0;i--)
    {
        if((board[kingRow][i] >= 'a') && (board[kingRow][i] <= 'z'))
        {
            break;
        }
        else if((board[kingRow][i] == 'R') || (board[kingRow][i] == 'Q'))
        {
            return 1;
        }
        else if((board[kingRow][i] == ' '))
        {}
        else
        {
            break;
        }
    
    }
    return 0;
    }
}
