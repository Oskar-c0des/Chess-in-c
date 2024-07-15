#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#define BOARD_SIZE 8


typedef struct{
    char type;
    char colour;
} Board;

Board board[BOARD_SIZE][BOARD_SIZE];

void initBoard()
{
    board[0][0].type = board[0][7].type = board[7][0].type = board[7][7].type = 'R';
    board[0][1].type = board[0][6].type = board[7][1].type = board[7][6].type = 'N';
    board[0][2].type = board[0][5].type = board[7][2].type = board[7][5].type = 'B';
    board[0][3].type = board[7][3].type = 'Q';
    board[0][4].type = board[7][4].type = 'K';

    for(int i=0;i<BOARD_SIZE;i++)
    {
        board[1][i].type = board[6][i].type = 'P';
        board[0][i].colour = 'B';
        board[1][i].colour = 'B';
        board[6][i].colour = 'W';
        board[7][i].colour = 'W';
        for(int j=2;j<6;j++)
        {
            board[j][i].type = '.';
        }
    }
}

void printBoard()
{
    for(int i=0;i<BOARD_SIZE;i++)
    {
        printf("\n%d",i);
        for(int j=0;j<BOARD_SIZE;j++)
        {
            printf(" %c ", board[i][j].type);
        }
    }
    printf("\n ");
    for(int i=0;i<BOARD_SIZE;i++)
    {
        printf(" %d ", i );
    }
    printf("\n");
}

//checking all possible valid moves
bool isValidMove(int startRow, int startCol, int endRow, int endCol, int turn)
{
    char piece = board[startRow][startCol].type;
    //char colour = board[startRow][startCol].colour;
    if(startRow < 0 || startRow >= BOARD_SIZE || startCol < 0 || startCol >= BOARD_SIZE ||
        endRow < 0 || endRow >= BOARD_SIZE || endCol < 0 || endCol >= BOARD_SIZE){
        return false;
        }

        if(piece == 'P' && (board[startRow+2][startCol].type == '.'||board[startRow-2][startCol].type == '.')){printf("ahhhhhhhhhhhhh");return true;}
        if(piece == 'P' && (board[startRow+1][startCol].type == '.'||board[startRow-1][startCol].type == '.')){printf("ahhhhhhhhhhhhh");return true;}
        return false;

}
/*
if piece is PAWN and it's in its starting pos available moves are 2 ahead if square is clear
if piece is PAWN and it's not in its start pos available moves are 1 ahead if square is clear

*/


void movePiece(int startRow, int startCol, int endRow, int endCol, int *turn)
{
    //for an index position we must check: what piece it is, what moves it can make, what move it will make
    int round = *turn;
    if(isValidMove(startRow,endRow,startCol,endCol,round))
    {
        board[endRow][endCol].type = board[startRow][startCol].type;
        board[startRow][startCol].type = '.';
        printBoard();
    }
}

int main()
{
    int playerTurn = 1; //odd is white even is black
    initBoard();
    printBoard();
    char piece;
    int startRow, startCol, endRow, endCol;
    do
    {
        if(playerTurn %2 !=0 )
        {
            printf("\nplayer turn: %d ", playerTurn);
            printf("White's turn\n");
            printf("Enter your move (startRow startCol endRow endCol)\n");
            scanf("%d %d %d %d",&startRow, &startCol, &endRow, &endCol);
            movePiece(startRow, startCol, endRow, endCol, &playerTurn);
            playerTurn++;
        }
        else
        {
            printf("\nplayer turn: %d ", playerTurn);
            printf("Black's turn\n");
            printf("Enter your move (startRow startCol endRow endCol)\n");
            scanf("%d %d %d %d", &startRow, &startCol, &endRow, &endCol);
            movePiece(startRow, startCol, endRow, endCol, &playerTurn);
            playerTurn++;
        }
    }while(isValidMove(startRow, startCol, endRow, endCol, playerTurn));
    return 0;
}




