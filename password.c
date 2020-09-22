/* 
Title: password.c
Description: This program evaluates a randomly generated password to determine if it is strong or not.
Author: Omar Abdelrahman
*/

#include<stdio.h>
#include<time.h> // including time for using time() function
#include<stdlib.h> // including stdlib for using rand() function
#include<stdbool.h> // including stdbool for using bool data type

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

// Function to determine if a given password is strong or not
int is_strong_password(int a[], int n){
    // initialize boolean variables to false
    bool is_upper = false;
    bool is_lower = false;
    bool is_digit = false;
    bool is_char = false;

    // loop through every character in the randomly generated password
    for(int i=0; i<n; i++){
        if(a[i] >= 48 && a[i] <= 57){ // check if a digit exists at least once
            is_digit = true;
        }
        else if(a[i] >= 65 && a[i] <= 90){ // check if an uppercase letter exists at least once
            is_upper = true;
        }
        else if(a[i] >= 97 && a[i] <= 122){ // check if a lowercase letter exists at least once
            is_lower = true;
        }
        else{ // check if a special character exists at least once
            is_char = true;
        }
    }

    if(is_upper && is_lower && is_digit && is_char){ // check if all the criteria is met
        return 1; // strong password
    }
    else{
        return 0; // not strong password
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

    generate_values(a, n); // calling function to generate values
    for(i=0; i<n; i++){
        printf("%c", a[i]); // printing the random string
    }
    printf("\n");
    if (is_strong_password(a, n) == 1){
        printf("A strong password");
    }
    else{
        printf("NOT a strong password");
    }
    printf("\n");
    
    return 0;
}