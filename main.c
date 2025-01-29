

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
extern void loadgame(char board[8][8]);
extern bool isCastlingLegal(char currentRow,char currentCol,char row,char col,char board[8][8]);

//global variable
int blackkingMoved = 0 ;
int whitekingMoved = 0 ;
int leftKing = 0 ;
int rightKing = 0 ;
int rightking = 0 ;
int leftking = 0 ;
int turn = 0;

int main()
{
    
    char loadOrNew;
    labelLoad:
    printf("Press (L) to Load Previous game, (N) for New game: ");
    scanf("%c",&loadOrNew);
    printf("%c",loadOrNew);
    if(loadOrNew != 'L' && loadOrNew != 'l' && loadOrNew != 'N' && loadOrNew != 'n')
    {
        printf("Invalid!\n");
        goto labelLoad;
    }

    char currentRow,currentCol,row,col ;
    char board[8][8];
    if(loadOrNew == 'L' || loadOrNew == 'l' )
    {
        loadgame(board);
    }
    else    //if game is loaded board should not e filled from start
    {fillBoard(board);
    printf("Boardfilled\n");}
    displayBoard(board);
    
    if(loadOrNew == 'n' || loadOrNew == 'N')
    {
        FILE *fp1 = fopen("Save.txt","w");
        fprintf(fp1," ");
        fclose(fp1); 
    }

    FILE *fp = fopen("Save.txt","a");
    

    while(1){
    if(turn %2 == 0){label1:
    printf("White's Turn(eg B2-A1 ): ");
    scanf(" %c%c - %c%c",&currentCol,&currentRow,&col,&row);
    
    (currentCol>='a' && currentCol<='h')?(currentCol -= 32):(currentCol);  //convert lower case to upper
    (col>='a' && col<='h')?(col -= 32):(col);
    
    currentRow--; //array index is less than visible row/col labels
    row--;
    
    if(!(board[currentRow-48][currentCol-65] >= 'A' && board[currentRow -48][currentCol -65] <= 'Z' ))
    {
        printf("Not Your Piece! Try Again...\n");
        goto label1;
    }

    if(!(IsMoveLegal(currentRow,currentCol,row,col,board)))//1 is returned for legal move
    {
        printf("Invalid MOVE! Try Again...\n");
        goto label1;
    }
    char temp = board[row-48][col-65];
    board[row-48][col-65] = board[currentRow-48][currentCol-65];
    board[currentRow-48][currentCol-65] = ' ';
    if(isWhiteKingInCheck(board))
    {
        printf("\n--------<!White-King In Check!>--------TRY AGAIN\n\n");
        board[currentRow-48][currentCol-65] = board[row-48][col-65]  ;
        board[row - 48][col-65] = temp;
        goto label1;
    } 
    if(board[currentRow - 48][currentCol -65 ] == 'P' && row == '7')
    {PawnPromotion(currentRow,currentCol,row,col,board);}
    board[currentRow-48][currentCol-65] = ' ';//change previous index to ' ' after condition check for P
    displayBoard(board);
    if(isBlackKingInCheck(board))
    {
        printf("\n--------<!Black-King In Check!>--------\n\n");
        if(isCheckMate(board))
        {        
        printf("\n\t____________________\n\tGame Over!... CHECKMATE\n");                
            printf("White Wins\n");
            return 0;

        }
    }


    turn++;
    fprintf(fp," %c%c - %c%c\n",currentCol,currentRow,col,row);//for storing white's turns
    }
    label2:
    printf("Black's Turn(eg B2-A1 ): ");
    scanf(" %c%c-%c%c",&currentCol,&currentRow,&col,&row);
    currentRow--;
    row--;
    (currentCol>='a' && currentCol<='h')?(currentCol -= 32):(currentCol);  //convert lower case to upper
    (col>='a' && col<='h')?(col -= 32):(col);

    if(!(board[currentRow -48 ][currentCol -65 ] >= 'a' && board[currentRow -48 ][currentCol -65 ] <= 'z' ))
    {
        printf("Not Your Piece! Try Again...\n");
        goto label2;
    }
    if(!(IsMoveLegal(currentRow,currentCol,row,col,board)))//1 is returned for legal move
    {
        printf("Invalid Move! Try Again...\n");
        goto label2;
    }
    int temp = board[row-48][col-65];
    board[row-48][col-65] = board[currentRow-48][currentCol-65];
    board[currentRow-48][currentCol-65] = ' ';
    if(isBlackKingInCheck(board))
    {
        printf("\n--------<!Black-King In Check!>--------TRY AGAIN\n\n");
        board[currentRow-48][currentCol-65] = board[row-48][col-65]  ;
        board[row - 48][col-65] = temp;

        goto label2;
    } 
    displayBoard(board);
    if(isWhiteKingInCheck(board))
    {
        printf("\n--------<!White-King In Check!>--------\n\n");
        if(isCheckMate(board))
        { 
            printf("King Out Of Moves!...\n");       
            printf("\n\t____________________\n\tGame Over!... CHECKMATE\n");                
            printf("Black Wins\n");
            return 0;
            }
        }
    
    
    fprintf(fp," %c%c - %c%c\n",currentCol,currentRow,col,row); 
    turn++;
    }
    
    fclose(fp);
}
