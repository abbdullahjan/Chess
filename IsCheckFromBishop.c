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



bool isCheckFromBishop(char kingRow,char kingCol,char board[8][8])
{
    //check for threat upward
    if(board[kingRow][kingCol] == 'K') //need to differentiate enemy pieces by knowing current pieces
    {   //check for downleft to upside right diagonals
        for(int i=1;((i+kingRow)<8) && ((i+kingCol)<8) ;i++)
        {
            if(board[kingRow + i][kingCol + i] >= 'A' && board[kingRow + i][kingCol + i] <= 'Z')
            {
                break;
            }
            else if(board[kingRow + i][kingCol + i] == 'b' || board[kingRow + i][kingCol + i] == 'q')
            {
                return 1;
            }
            else if(board[kingRow + i][kingCol + i] == ' ')//to protect 'space' from else statement
            {}
            else
            {
                break;
            }
        }
        //check for upright to downleft
        for(int i=1;((kingRow-i)>=0) && ((kingCol-i)>=0) ;i++)
        {
            if(board[kingRow - i][kingCol - i] >= 'A' && board[kingRow - i][kingCol - i] <= 'Z')
            {
                break;
            }
            else if(board[kingRow - i][kingCol - i] == 'b' || board[kingRow - i][kingCol - i] == 'q')
            {
                return 1;
            }
            else if(board[kingRow - i][kingCol - i] == ' ')//to protect 'space' from else statement
            {}
            else
            {
                break;
            }
        }
        //check for bottomright to topleft
        for(int i=1;((i+kingRow)<8) && ((kingCol-i)>=0) ;i++)
        {   
            if((board[kingRow + i][kingCol - i] >= 'A') && (board[kingRow + i][kingCol - i] <= 'Z'))
            {
                break;
            }
            else if(board[kingRow + i][kingCol - i] == 'b' || board[kingRow + i][kingCol - i] == 'q')
            {
                printf("%d214\n",i);
                return 1;
            }
            else if(board[kingRow + i][kingCol - i] == ' ')//to protect 'space' from else statement
            {}
            else
            {
                break;
            }
        }//check for topleft to bottomright
        for(int i=1;((kingRow-i)<8) && ((kingCol+i)>=0) ;i++)
        {
            if(board[kingRow - i][kingCol + i] >= 'A' && board[kingRow - i][kingCol + i] <= 'Z')
            {
                break;
            }
            else if(board[kingRow - i][kingCol + i] == 'b' || board[kingRow - i][kingCol + i] == 'q')
            {
                return 1;
            }
            else if(board[kingRow - i][kingCol + i] == ' ')
            {}
            else
            {
                break;
            }
        }
        return 0;
    }
    else
    {   //check for downleft to upside right diagonals
        for(int i=1;((i+kingRow)<8) && ((i+kingCol)<8) ;i++)
        {
            if(board[kingRow + i][kingCol + i] >= 'a' && board[kingRow + i][kingCol + i] <= 'z')
            {
                break;
            }
            else if(board[kingRow + i][kingCol + i] == 'B' || board[kingRow + i][kingCol + i] == 'Q')
            {
                return 1;
            }
            else if(board[kingRow + i][kingCol + i] == ' ')//to protect 'space' from else statement
            {}
            else
            {
                break;
            }
        }
        //check for upright to downleft
        for(int i=1;((kingRow-i)>=0) && ((kingCol-i)>=0) ;i++)
        {
            if(board[kingRow - i][kingCol - i] >= 'a' && board[kingRow - i][kingCol - i] <= 'z')
            {
                break;
            }
            else if(board[kingRow - i][kingCol - i] == 'B' || board[kingRow - i][kingCol - i] == 'Q')
            {
                return 1;
            }
            else if(board[kingRow - i][kingCol - i] == ' ')//to protect 'space' from else statement
            {}
            else
            {
                break;
            }
        }
        //check for bottomright to topleft
        for(int i=1;((i+kingRow)<8) && ((kingCol-i)>=0) ;i++)
        {
            if(board[kingRow + i][kingCol - i] >= 'a' && board[kingRow + i][kingCol - i] <= 'z')
            {
                break;
            }
            else if(board[kingRow + i][kingCol - i] == 'B' || board[kingRow + i][kingCol - i] == 'Q')
            {
                return 1;
            }
            else if(board[kingRow + i][kingCol - i] == ' ')//to protect 'space' from else statement
            {}
            else
            {
                break;
            }
        }//check for topleft to bottomright
        for(int i=1;((kingRow-i)<8) && ((kingCol+i)>=0) ;i++)
        {
            if(board[kingRow - i][kingCol + i] >= 'a' && board[kingRow - i][kingCol + i] <= 'z')
            {
                break;
            }
            else if(board[kingRow - i][kingCol + i] == 'B' || board[kingRow - i][kingCol + i] == 'Q')
            {
                return 1;
            }
            else if(board[kingRow - i][kingCol + i] == ' ')
            {}
            else
            {
                break;
            }
        }
        return 0;
    }
}
