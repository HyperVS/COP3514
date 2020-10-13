/* 
Title: consonants.c
Description: This program reads a line of input until enter or a newline character is enterred and prints out all the consonants in the input.
Author:  Omar Abdelrahman
*/

#include<stdio.h>

// main function
int main(){
    int i=0;
    char ch;
    // char array to store all the consonants
    char consonant[100]={""};

    // do while loop to take user input until user presses enter
    do{
        // get keyboard input from getchar() function
        ch = getchar();
        // check if the entered character is a consonant or not
        if(((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) && !(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
            ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')){
                consonant[i] = ch;
                i++;
            }
    } while(ch!='\n'); // loop until user presses enter

    // output the consonant array
    printf("Consonants : ");
    printf("%s", consonant);

    printf("\n");
    return 0;
}