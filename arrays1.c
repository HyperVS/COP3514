/* 
Title: arrays1.c
Description: This program splits an array into two arrays, one containing the elements before zero and one containing the 
elements after zero.
Author: Omar Abdelrahman
*/

#include<stdio.h>

int compute(int *a, int n){
    int i=0;
    for(i=0;i<n;i++){
        if(*a==0){ // if array element is equal to 0
            return i;
            break;
        }
    a++;
    }
    return n;
}

int main(){
  
    int length,i,j = 0; // declaring length, i, and j and initializing j to 0 to avoid compile errors
  
    printf("Enter theh length of the array: ");
    scanf("%d",&length);
  
    // Declaring the arrays 
    int array[length];
    int array1[length];
    int array2[length];

    printf("Enter the elements of the array: ");
    for(i=0;i<length;i++){
        scanf("%d",&array[i]);
    }

    int index = compute(array,length); // calling the compute function

    for(i=0;i<index;i++){ // for loop used to populate array1
        array1[i] = array[i];
    }
  
    for(i=index;i<length;i++){ // for loop used to populate array2
        array2[j] = array[i];
        j++;
    }
  
    printf("Output:\n");
    printf("Array 1: ");
    for(i=0;i<index;i++){
        printf("%d ",array1[i]);
    }

    printf("\n");
    printf("Array 2: ");
    for(i=0;i<j;i++){
        printf("%d ",array2[i]);
    }

    printf("\n");
    return 0; // Exit the program
}