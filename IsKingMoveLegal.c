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
extern bool isCastlingLegal(char currentRow,char currentCol,char row,char col,char board[8][8]);

//global variable
extern int blackkingMoved  ;
extern int whitekingMoved  ;
extern int leftKing  ;
extern int rightKing  ;
extern int rightking  ;
extern int leftking  ;
extern int turn ;

bool isKingMoveLegal(char currentRow,char currentCol,char row,char col,char board[8][8])
{
    int rowDifference = abs(currentRow - row);
    int colDifference = abs(currentCol - col);

    if(rowDifference > 1)
    {
    return 0;
    }

    if(colDifference > 1)
    {
    if(  (isCastlingLegal( currentRow,currentCol,row,col,board))   )
    return 1;
    else 
    return 0;
    }

    if(board[currentRow - 48][currentCol - 65] == 'K' ) //show it's white's turn, 
    {
        //as it's white's turn, upper case alphabets, already at recieving index, are not allowed
        // ie cannot move King to square occupied by same player

        //instead of selecting pieces, we give range of all capital letters
        if((board[row - 48][col - 65] >= 'A' && board[row - 48][col - 65]<='Z') )
        {
            return 0;
        }
    whitekingMoved++;

    }
    else
    {
        if((board[row - 48][col - 65] >= 'a' && board[row - 48][col - 65]<='z') )
        {
            return 0;
        }
    blackkingMoved++;

    }

    
    return 1;

}
