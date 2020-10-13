/* 
Title: consonants.c
Description: This program takes command line arguments as input and prints out all the consonants in the input.
Author:  Omar Abdelrahman
*/

#include <stdio.h>
#include <string.h>

// Main function
int main(int argc, char *argv[]){
    
    // Declaring variables
    int i=0;
    char consonant[100];
  
    for(i=1;i<argc;i++){
        int j=0;

        // Copying each command line argument to the array
        strcpy(consonant,argv[i]);
    
        // Iterating over the array
        while(consonant[j]!='\0'){

            // Checking each character to see if its a consonant and printing it 
            if(((consonant[j] >= 'a' && consonant[j] <= 'z') || (consonant[j] >= 'A' && consonant[j] <= 'Z')) && !(consonant[j]=='a' || consonant[j]=='e' || consonant[j]=='i' || consonant[j]=='o' || consonant[j]=='u' ||
            consonant[j]=='A' || consonant[j]=='E' || consonant[j]=='I' || consonant[j]=='O' || consonant[j]=='U')){

                printf("%c",consonant[j]);
            }
            j++; // Incrementing to get next character
        }
    }
    
    printf("\n");
    return 0;
}