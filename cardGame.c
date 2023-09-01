//
// Created by josep on 01/09/2023.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
    return 0;
}

int prettyDisplay(char face, char suit){
    switch(face){
        //ace
        case 'A':
            printf("Ace of ");
            break;
        //jack
        case 'j':
            printf("Jack of ");
            break;
        //queen
        case 'Q':
            printf("Queen of ");
            break;
        //king
        case 'K':
            printf("King of ");
            break;
        //10
        case 't':
            printf("10 of ");
            break;
        //numbers
        default:
            printf("%c of ",face);
    }
    switch(suit){
        case 'H':
            printf("Hearts\n");
            break;
        case 'D':
            printf("Diamonds\n");
            break;
        case 'C':
            printf("Clubs\n");
            break;
        case 'S':
            printf("Spades\n");
            break;
    }
    return 0;
}

int showDeck(char* deck){
    char face,suit;
    for(int i = 0;i < 52;i++){
        face = *(deck+i*2+0);
        suit = *(deck+i*2+1);
        printf("\"%c%c\"\t",face,suit);
    }
    return 0;
}

int prettyShowDeck(char* deck){
    char face,suit;
    for(int i = 0;i < 52;i++){
        face = *(deck+i*2+0);
        suit = *(deck+i*2+1);
        prettyDisplay(face,suit);
    }
    return 0;
}

int shuffleDeck(char* deck, int deckSize, int shuffleNo){
    //take deck and shuffle cards
    srand(time(NULL));
    for(int i = 0; i < shuffleNo; i++){
        int firstIndex = rand()%51;
        int secondIndex = rand()%51;
        char tempCard[2] = {*(deck+firstIndex*2+0),*(deck+firstIndex*2+1)};

        *(deck+firstIndex*2+0) = *(deck+secondIndex*2+0);
        *(deck+firstIndex*2+1) = *(deck+secondIndex*2+1);

        *(deck+secondIndex*2+0) = tempCard[0];
        *(deck+secondIndex*2+1) = tempCard[1];
    }
    return 0;
}

int cardGame(){
    char deck[52][2];
    //generate deck
    generateDeck(*deck);
    //show deck
    showDeck(*deck);
    //shuffle deck
    shuffleDeck(*deck,52,100);
    //show deck
    prettyShowDeck(*deck);
}