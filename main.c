#include <stdio.h>
#include "ticTacToe.h"
#include "cardGame.h"

int main(){
    int option;
    int playing=1;

    while(playing) {
        printf("Fun games Written in C options below\n"
               "\t1. Tic Toe Game\n"
               "\t2. Card Game\n"
               "\t3. Quit\n"
               "Select option: \n");
        scanf("%d", &option);
        scanf("%*c");
        switch (option) {
            case 1:
                ticTacToe();
                break;
            case 2:
                cardGame();
                break;
            case 3:
                printf("Exiting games\n");
                playing = 0;
                break;
            default:
                printf("Invalid option\n");
        }
    }

};