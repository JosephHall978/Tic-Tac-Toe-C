//
// Created by josep on 01/09/2023.
//
#include <stdio.h>
//for random number generator
#include <time.h>
#include <stdlib.h>

//tic tac toe
//add token to board
void addToken(int row,int column,char* board,char token){
    *(board+row*3+column) = token;
}
//reset board
void resetBoard(char *board) {
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            *(board+i*3+j)=' ';
        }
    }
}

void displayBoard(char* board){
    char (*ptr)[3];
    ptr = board;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            printf(" %c ",*(*(ptr+i)+j));
        }
        printf("\n");
    }
}
//check winner
void checkWinner(int turn,int* winner,char* board){
    char(*ptr)[3];
    ptr = board;
    char searchToken = turn==0?'X':'O';
    //printf("%c",searchToken);
    int vertical = 0;
    int horizontal = 0;
    //check horizontal and vertical
    for(int i=0; i < 3;i++){
        for(int j=0; j<3;j++){
            if(*(*(ptr+i)+j)==searchToken){
                vertical++;
            }
            if(*(*(ptr+j)+i)==searchToken){
                horizontal++;
            }
        }
        if(vertical==3||horizontal==3){
            *winner=(searchToken=='X')?1:2;
        }
        vertical=0;
        horizontal=0;
    }
    //check diagonal
    if(*(*(ptr+1)+1)==searchToken){//check centre
        if((*(*(ptr))==searchToken && *(*(ptr+2)+2)==searchToken)||(*(*(ptr+2))==searchToken && *(*(ptr)+2)==searchToken)){
            *winner=(searchToken=='X')?1:2;
        }
    }
}
//valid move
int valid(int row, int column,char* board){//1 valid, 0 invalid
    if(row < 3 && column < 3){
        if(*(board+row*3+column)==' '){
            return 1;
        }
    }
    return 0;
}
//opponent
void opponentMove(char* board) {
    int rowMove, columnMove;
    int moves[9][2] = {{0, 0},
                       {0, 1},
                       {0, 2},
                       {1, 0},
                       {1, 1},
                       {1, 2},
                       {2, 0},
                       {2, 1},
                       {2, 2}};
    //initialise random number
    srand(time(NULL));
    while(1){
        //generate move
        int move = rand() % 8;
        rowMove = moves[move][0];
        columnMove = moves[move][1];

        if (valid(rowMove, columnMove, board)) {
            addToken(rowMove, columnMove, board, 'O');
            return;
        }
    }
}
//player
void playerMove(char* board){
    int rowMove,columnMove;
    while(1==1) {
        printf("Enter row number: ");
        scanf("%d", &rowMove);
        printf("Enter column number: ");
        scanf("%*c");
        scanf("%d", &columnMove);
        //input
        if (valid(rowMove, columnMove, board)) {
            addToken(rowMove, columnMove, board, 'X');
            return;
        }
    }

}

int ticTacToe() {
    int turn = 1;
    int winner = 0;//0 active game, 1 player win, 2 computer win, 3 draw
    int moves = 0;
    char board[3][3];

    resetBoard(*board);
    while(winner==0) {
        printf("It is %s's turn!\n", (turn == 1) ? "Player" : "Opponent");
        displayBoard(*board);
        if (turn == 1) {
            playerMove(*board);
            turn = 0;
        } else {
            opponentMove(*board);
            turn = 1;
        }
        checkWinner(turn,&winner,*board);
        if(moves >= 8){
            winner = 3;
        }else{
            moves++;
        }
    }
    printf("%s",(winner==1)?"Player wins":(winner==2)?"Opponent wins":(winner==3)?"No one won":"Error");
    return winner;
}