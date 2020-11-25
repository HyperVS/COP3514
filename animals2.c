/* 
Title: animals.c
Description: This program sorts dogs and cats by age in ascending order and stores them in seperate output files.
Author: Omar Abdelrahman
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// structure for animal
struct animal{
    char name[100];
    char species[100];
    char gender[10];
    int age;
    float weight;
};

int compare_age(const void *p, const void *q);

// Function to sort animals based on age
void sort_animals(struct animal list[], int n){

    // Declaring variables
    int i, j, min_index;

    for (i = 0; i < n-1; i++){
        // Find the minimum element in unsorted array
        min_index = i;
        for (j = i+1; j < n; j++)
          if (list[j].age < list[min_index].age)
            min_index = j;

        // Swap the found minimum element with the first element
        struct animal temp = list[min_index];
        list[min_index] = list[i];
        list[i] = temp;
    }
}

// Main function
int main(){
    
    int i, count = 0;
    struct animal animals[200];
    struct animal input;
    char filename[100];
    
    printf("\nEnter the file name: ");
    scanf("%s", filename);
    printf("Output file name:\nsorted_dogs.txt\nsorted_cats.txt\n");

    FILE *fp;
    fp = fopen (filename, "r");
    if (fp == NULL){
        printf("Failed to open the input file.\n");
        return 1;
    }
    
    // Insert file contents to array and close the file
    while(fscanf(fp, "%s %s %s %d %f", input.name, input.species, input.gender, &input.age, &input.weight)!=EOF)
        animals[count++] = input;
    fclose (fp);

    // Call the quick sort function
    qsort(animals, count, sizeof(struct animal), compare_age);
    //sort_animals(animals, count);

    // Open files for writing
    FILE *out1, *out2;
    out1 = fopen("sorted_dogs.txt", "w");
    out2 = fopen("sorted_cats.txt", "w");

    for(i=0; i<count; i++){

        if(strcmp(animals[i].species, "dog")==0){
            fprintf(out1, "%s\t%s\t%d\t%.2f\n", animals[i].name, animals[i].gender, animals[i].age, animals[i].weight);
        }

        else if(strcmp(animals[i].species, "cat")==0){
            fprintf(out2, "%s\t%s\t%d\t%.2f\n", animals[i].name, animals[i].gender, animals[i].age, animals[i].weight);
        }
    }
    
    fclose(out1);
    fclose(out2);
    return 0;

}

int compare_age(const void* p, const void* q){

    if (((struct animal *) p)->age < ((struct animal *) q)->age){
        return -1;
    }
        
    else if (((struct animal *) p)->age == ((struct animal *) q)->age){
        return 0;
    }
    
    else{
        return 1;
    }   
}