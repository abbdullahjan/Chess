//SP24-BCS-142      ABDULLAH JAN
//SP24-BCS-174      M.MUSTAFA

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



void displayBoard(char board[8][8])
{
    printf("   A   B   C   D   E   F   G   H");
    //print ONE line after Alphabets
    printf("\n %c",218);  //print left most upside L
    for(int k=0;k<7;k++)  //loop once prints __| (but in sync)
        printf("%c%c%c%c",196,196,196,194);
    printf("%c%c%c%c\n",196,196,196,191); //this statement prints the ending col to make it in sync
    for(int i=7;i>=0;i--)
    {
        printf("%d%c",i+1,179); 
        for(int j=0;j<8;j++)
        {
            if(board[i][j] == 'P') //differentiating P from p on board is difficult, so printing whites P differently
            {printf(" %c`%c",board[i][j],179);
            }
            else
            printf(" %c %c",board[i][j],179);
        }
        printf("%d",i+1);
        if(i==0)
        {
           printf("\n %c",192);
        for(int k=0;k<7;k++)
        printf("%c%c%c%c",196,196,196,193);
        printf("%c%c%c%c\n",196,196,196,217); 
        }
        else    
        {
        printf("\n %c",195);
        for(int k=0;k<7;k++)
        printf("%c%c%c%c",196,196,196,197);
        printf("%c%c%c%c\n",196,196,196,180);}
    }
    printf("   A   B   C   D   E   F   G   H\n"); 
}
