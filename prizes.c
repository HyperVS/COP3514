/*
Title: prizes.c
Description: This program simulates a random prize from the pointer array each time the user presses 1 to play.
Author: Omar Abdelrahman
*/

#include <stdio.h>   
#include <stdlib.h> 
#include <string.h> 
#include <time.h>

// function for the game

void game(char* prizes[]){
    printf("Press '1' to play and '0' to exit\n");
    int option;
    scanf("%d", &option); // stores choice of user

    char prize[10];
    if(option==0){ // choice is 0
        exit(0);
    }else{ // if choice is 1
        int a = (rand()% 12 + 0); // generating random number between 0 and 11
        srand(time(NULL));
        if(a!=5 && a!=11){
            printf("%s", prizes[a]);
            exit(0);
        }else if(a==11){
            game(prizes);
        }else if(a==5){
            printf("You have won the jackpot and received 4000 points!\n");
            game(prizes);
        }
    }
}

int main() {
    srand(time(NULL)); // causes rand() function to generate different values every time

    // storing values of prizes
    char* prizes[] = { "Pizza", "Shirt", "Sweater", "Raspberry", "Brown Sugar", "Star", "Butter",
    "Apple", "Blackberry Jelly", "Strawberry Cake", "Bacon", "Play Again" };

    game(prizes); // calling the game function

    return 0;
}