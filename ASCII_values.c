/* 
Title: ASCII_values.c
Description: This program creates a randomized integer array of randomized length and prints it.
Author: Omar Abdelrahman
*/

#include<stdio.h>
#include<time.h> // including time for using time() function
#include<stdlib.h> // including stdlib for using rand() function

// Function to generate random ASCII values
void generate_values(int a[], int n){
    int i; // loop counter

    // Setting lower and upper boundaries for generating random number in between 33 and 126
    int lower = 33, upper = 126;
    
    // Setting seed for random integer generator
    srand(time(NULL));

    // Generating random ASCII values and storing each one in the array
    for(i=0; i<n; i++){
    a[i] = (rand() % (upper - lower + 1)) + lower;
    }
}

int main(){

    int lower = 8, upper = 15;
    int i; // loop counter

    // Setting seed for random integer generator
    srand(time(NULL));

    // Generating random number in range of 8 to 15
    int n = (rand() % (upper - lower + 1)) + lower;
    int a[n]; // declaring array
    generate_values(a, n); // Calling function

    for(i=0; i<n; i++){
    // Printing randomly generated array values as ASCII characters using %c in printf() function
    printf("%c", a[i]);
    }
    printf("\n");

    return 0;
}