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
extern int blackkingMoved ;
extern int whitekingMoved ;
extern int leftKing ;
extern int rightKing ;
extern int rightking ;
extern int leftking ;
extern int turn;

void loadgame(char board[8][8])
{
    
    fillBoard(board);

    FILE *fp = fopen("save.txt", "r");
    char currentRow,currentCol,row,col ;

    while(getc(fp) != EOF)
    {
        turn ++;
        fscanf(fp," %c%c - %c%c",&currentCol,&currentRow,&col,&row);
        int kingpiece;
        if(board[currentRow - 48][currentCol-65] =='k'  )
        {
            kingpiece = 0 ;
        }
        if(board[currentRow - 48][currentCol-65] =='K')
        {
            kingpiece = 1;
        }
        if(board[currentRow - 48][currentCol-65] =='k' || board[currentRow - 48][currentCol-65] =='K')
        {
            //this condition is used if castling was done
            (kingpiece == 1)?((col - currentCol == 2)?(board[0][7]=' ',board[0][5]='R'):(board[0][0]=' ',board[0][3]='R')  ):((col - currentCol == 2)?(board[7][7]=' ',board[7][5]='R'):(board[7][0]=' ',board[7][3]='R') );
        }
        board[row-48][col-65] = board[currentRow-48][currentCol-65];
        board[currentRow-48][currentCol-65] = ' ';
        getc(fp);
    }
    fclose(fp);
}