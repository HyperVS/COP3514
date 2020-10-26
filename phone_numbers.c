/* 
Title: phone_numbers.c
Description: This program extracts phone numbers from an input text file and stores them in a seperate output file.
Author: Omar Abdelrahman
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 10000

// Function to extract phone numbers from the input file and store in the string phone
void extract_phone(char *input, char *phone){
    char *temp;
    strcpy(phone, "");

    // Split the string at the first _
    temp = strtok(input, "_");

    // Repeat the split for two times to get the phone number
    temp = strtok(NULL, "_");
    temp = strtok(NULL, "_");

    // Copy the string to the phone pointer
    strcpy(phone, temp);
}

// Main function
int main(){

    char buffer[MAX_LEN];
    char phone[MAX_LEN];
    char filename[100], outputfilename[100] = "phone_";

    printf("\nEnter the file name: ");
    scanf("%s", filename);
    
    // Concatenate input file name to output file name
    strcat(outputfilename, filename);
    printf("Output file name : %s\n", outputfilename);

    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Failed to open the input file.\n");
        return 1;
    }

    FILE *fq;
    fq = fopen(outputfilename, "w");
    if (fq == NULL){
        printf("Failed to open the output file.\n");
        return 1;
    }

    while (fgets(buffer, MAX_LEN, fp)){
        // Call the extract_phone function
        extract_phone(buffer, phone);
        // Write the returned value to the file
        fprintf(fq, "%s", phone);
    }

    fclose(fp);
    fclose(fq);
    return 0;
}