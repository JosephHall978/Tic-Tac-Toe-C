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

int searchAce(char* deck){
    for(int i=0;i<52;i++){
        char card[2] = {*(deck+i*2),*(deck+i*2+1)};
        if(card[0] == 'A' && card[1] == 'S'){
            return i;
        }
    }
    return INT_MAX;
}

int computerGuess(int low, int high){
    int guess;
    high--,low++;
    int difference = high-low;//find range of high and low
    srand(time(NULL));
    if(difference != 0) {//prevents error from division by zero
        guess = rand() % (difference) + low;//shift range up so guess is between high and low
    }else{
        return high;
    }
    return guess;
}

int cardGame(){
    char deck[52][2];
    //generate deck
    generateDeck(*deck);
    //shuffle deck
    shuffleDeck(*deck,52,100);
    /*
     * Find the ace of spades
     * Guess a card
     * When you guess the card you will find its identity
     * You will then find out if the guess is higher or lower
     */
    int winner = 0;
    int acePosition = searchAce(*deck);
    int low = 0;
    int high = 52;
    while(winner == 0) {//0 is active, 1 is player win, 2 is computer win
        int guess;

        printf("Guess which card is the Ace of Spades: \n");
        scanf("%d*c", &guess);

        if(guess > 51 || guess < 0) {
            printf("Guess which card is the Ace of Spades: \n");
            scanf("%d*c", &guess);
        }

        prettyDisplay(deck[guess][0],deck[guess][1]);

        //high/low check
        if(guess > acePosition){
            printf("You guessed to high\n");
        }else{
            if(guess < acePosition){
                printf("You guessed to low\n");
            }
            else{
                winner = 1;
            }
        }
        //computer guess
        guess = computerGuess(low,high);
        printf("Computer guesses %d\n",guess);
        //computer adjusting guess range
        if(guess > acePosition){
            high = guess;
        }else{
            if(guess < acePosition){
                low = guess;
            }
            else{
                winner = 2;
            }
        }
    }
    printf("%s\n",(winner==1)?"Player wins":"Opponent wins");
}