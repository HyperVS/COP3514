/* 
Title: stars.c
Description: This program reads a line of input and displays the characters between the first two * characters.
Author: Omar Abdelrahman
*/

#include <stdio.h>

// Function to read a line
int read_line(char *str, int n){

    int ch, i = 0;

    while ((ch = getchar()) != '\n'){
        if (i < n){
            *str++ = ch;
            i++;
        }
    }

    *str = '\0';
    return i;
}

// Function to find the first 2 stars in the line of input and store all the characters in between them in s2
int search(char *s1, char *s2){
    
    int count = 0; // Count for the number of stars that exist in the line of input
    
    while (*s1 != '\0' && count < 2){ // Break loop when 2 stars are found
        if (*s1++ == '*')
            count++;
    }
    
    // If 2 stars aren't found, return 0
    if (count < 2){
        *s2 = '\0'; // Empty string
        return 0;
    }

    else{ // Find the characters between the first two stars

        // Point s1 to the first star character
        while (count > 0){
            s1--;
            if (*s1 == '*'){
                count--;
            }    
        }

        // Variable to store if first star was found or not
        int isFirstStar = 0; 

        // Loop through characters until end of string
        while (*s1 != '\0'){ 

            // Finding the first star
            if (*s1 == '*' && isFirstStar == 0){
                isFirstStar = 1;
            }

            // Finding the second star
            else if (*s1 == '*' && isFirstStar == 1){
                *s2 = '\0';
                return 1; // return to main
            }

            // If first star is found, store every character after it in s2
            else if (isFirstStar == 1){
                *s2++ = *s1;
            }

            // increment to get next character
            s1++;
        }
        return 1;
    }
}

int main(){

    char str1[1000];
    char str2[1000];
    int size, isValid; // isValid is equal to 1 if the input has 2 stars and is equal to 0 if it doesn't

    printf("Enter input string: ");
    size = read_line(str1, 1000);
    isValid = search(str1, str2);

    if (isValid == 0)
        printf("\nCould not find two * characters in the line of input.");
    else
        printf("\nOutput: %s", str2);

    printf("\n");
    return 0;
}