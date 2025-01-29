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

bool IsMoveLegal(char currentRow,char currentCol,char row,char col,char currentLocation[8][8])
{


    //gathering info for castling--if Rooks have moved, castling is not possible
    if(currentLocation[0][0] != 'R')
    leftKing ++ ;
    if(currentLocation[0][7] != 'R')
    rightKing ++ ;
    if(currentLocation[7][0] != 'r')
    leftking ++ ;
    if(currentLocation[7][7] != 'r')
    rightking ++ ;
    //--------------------------------------------------------------------

    if((row <'0' && row>='8') || (currentRow <'0' && currentRow>='8') )//Invalid next row and current row
    {
        
        if((col < 'A' && col >'H') || (currentCol < 'A' && currentCol >'H')) //Invalid next col & current col
        {                       
            return 0;       
        }    
    }
    //for both black and white pieces
    if(currentLocation[currentRow-48][currentCol-65] == 'P' || currentLocation[currentRow-48][currentCol-65] == 'p') //'A' - 65 = 0, first index , '0' - 48 = 0
    {
        return isPawnMoveLegal(currentRow,currentCol,row,col,currentLocation);
    }
    else if(currentLocation[currentRow-48][currentCol-65] == 'R' || currentLocation[currentRow-48][currentCol-65] == 'r') //'A' - 65 = 0, first index , '0' - 48 = 0
    {
        return isRookMoveLegal(currentRow,currentCol,row,col,currentLocation);
    }
    else if(currentLocation[currentRow-48][currentCol-65] == 'B' || currentLocation[currentRow-48][currentCol-65] == 'b') //'A' - 65 = 0, first index , '0' - 48 = 0
    {
        return isBishopMoveLegal(currentRow,currentCol,row,col,currentLocation);
    }
    else if(currentLocation[currentRow-48][currentCol-65] == 'Q' || currentLocation[currentRow-48][currentCol-65] == 'q') //'A' - 65 = 0, first index , '0' - 48 = 0
    {
        return isQueenMoveLegal(currentRow,currentCol,row,col,currentLocation);
    }
    else if(currentLocation[currentRow-48][currentCol-65] == 'N' || currentLocation[currentRow-48][currentCol-65] == 'n') //'A' - 65 = 0, first index , '0' - 48 = 0
    {
        return isKnightMoveLegal(currentRow,currentCol,row,col,currentLocation);
    }
    else if(currentLocation[currentRow-48][currentCol-65] == 'K' || currentLocation[currentRow-48][currentCol-65] == 'k') //'A' - 65 = 0, first index , '0' - 48 = 0
    {
        return isKingMoveLegal(currentRow,currentCol,row,col,currentLocation);
    }
    else
    {
        return 0;
    }
}