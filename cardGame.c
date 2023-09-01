//
// Created by josep on 01/09/2023.
//
#include <stdio.h>

int generateDeck(char* deck){
    char face[] = {'A','2','3','4','5'
                   ,'6','7','8','9','t',
                   'j','Q','K'};//t is 10, j is Jack, Q is queen, K is king
    char suit[] = {'H','D','C','S'};//H is Hearts, D is Diamonds, C is Clubs, S is spades

    int cardPosition = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            *(deck+cardPosition*2+0) = face[j];
            *(deck+cardPosition*2+1) = suit[i];
            cardPosition++;
        }
    }
    return 1;
}

int showDeck(char* deck){
    char face,suit;
    for(int i = 0;i < 52;i++){
        face = *(deck+i*2+0);
        suit = *(deck+i*2+1);
        printf("\"%c%c\"\t",face,suit);
    }
    return 1;
}

int shuffleDeck(char* deck, int deckSize){
    //take deck and shuffle cards
    return 1;
}

int cardGame(){
    char deck[52][2];
    //generate deck
    generateDeck(*deck);
    //show deck
    showDeck(*deck);
    //shuffle deck

    //show deck
}