/* 
Title: arrays2.c
Description: This program checks if an integer array contains three identical consecutive elements.
Author: Omar Abdelrahman
*/

#include<stdio.h>
#include<stdlib.h>

void search_three(int *a1,int *a2,int n,int *num_three){
  
    int index = 0; // Declaring and initializing the index to 0
    for(int i=0;i<n-2;i++){
        
        if((*(a1+i) == *(a1+i+1)) && (*(a1+i+1) == *(a1+i+2))){ // If there are three consecutive numbers
            *(a2+index) = *(a1+i);
            (*num_three)++;
            index++;
        }
    }
  
    if(index == 0){
        printf("The array does NOT contain identical consecutive elements");
        return;
    }

    printf("The array contains %d of identical consecutive elements: ",*num_three);

    for(int i=0;i<index;i++){
        printf("%d ",*(a2+i));
    }

    printf("\n");
}

int main(void) {

    int n;
    printf("Enter the length of the array: ");
    scanf("%d",&n);

    printf("\n");
    int a1[n];
    int a2[n];

    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a1[i]);
    }
    printf("\n");

    int count = 0; // Declaring and initializing count to 0
    int *num_three; 
    num_three = &count;

    search_three(a1,a2,n,num_three); // calling the search_three function

    return 0; // Exit the program
}