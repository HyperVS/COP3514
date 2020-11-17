#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "request.h"
#include "readline.h"

struct request *load(){
	struct request * list= NULL;
	struct request *prev, *new_node;
	char f_name[NAME_LEN+1];
	char l_name[NAME_LEN+1];
	char e_address[EMAIL_LEN+1];
	char class_name[CLASS_LEN+1];

	FILE *pFile;

        pFile = fopen("waiting_list.txt", "r");
	
	if(pFile == NULL)
	{
		printf("Error opening the file\n");
		return NULL;
	}

        while(!feof(pFile)&&!ferror(pFile))
	{
	       if(fscanf(pFile, "%s%s%s%s", e_address, class_name, f_name, l_name)== 4)
		{

 			 new_node = malloc(sizeof(struct request));
 			 if (new_node == NULL) {
    				printf("Database is full; loding error.\n");
    				return NULL;
 			 }

			strcpy(new_node->email, e_address);	
			strcpy(new_node->class, class_name);
			strcpy(new_node->first, f_name);
			strcpy(new_node->last, l_name);
			new_node->next = NULL;

			if(list == NULL)	
				list = new_node;
			else
				prev->next = new_node;
			prev = new_node;				
				
        	}
	}
	return list;
}

struct request *append(struct request *list){

	char class[CLASS_LEN+1];
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];

	printf("\nEnter the first name: ");
	scanf("%s",first);

	printf("\nEnter the last name: ");
	scanf("%s",last);

	printf("\nEnter the email address: ");
	scanf("%s",email);

	printf("\nEnter the class name: ");
	scanf("%s",class);
	
	struct request * new_node = (struct request*)malloc(sizeof(struct request));
	
	strcpy(new_node->first,first);
	strcpy(new_node->last,last);
	strcpy(new_node->email,email);
	strcpy(new_node->class,class);

	new_node->next = NULL;

	struct request *p = list;
	struct request *temp = list;

	while(p != NULL) {
		// Check if the data is already present
		if((strcmp(p->first,first)==0) && (strcmp(p->last,last)==0) && (strcmp(p->email,email)==0) && (strcmp(p->class,class)==0)) {
			printf("The data already exists in the waiting list.\n");
			return list;
		}
		temp = p;
		p = p->next;    
	}

	// If the list is empty, make it as first node
	if(list == NULL) {
		list = new_node;
		return list;
	}

	// Since data is not present, insert a new node at the bottom of the list
	temp->next = new_node;

	// Return list
	return list;

}

struct request *delete(struct request *list){

	char class[CLASS_LEN+1];
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];

	printf("\nEnter the first name: ");
	scanf("%s",first);

	printf("\nEnter the last name: ");
	scanf("%s",last);

	printf("\nEnter the email address: ");
	scanf("%s",email);

	printf("\nEnter the class name: ");
	scanf("%s",class);

	struct request *p = list;
	struct request *temp = list;

	while(p != NULL) {

		// Check the data to be deleted
		if((strcmp(p->first,first)==0) && (strcmp(p->last,last)==0) &&
			(strcmp(p->email,email)==0) && (strcmp(p->class,class)==0)) {
			break;
		}
		temp = p;
		p = p->next;    
	}

	// If no data is found, return list 
	if(p==NULL) {
		printf("There is no matching request to be deleted.\n");
		return list;
	} 

	// Change the link as data is found
	temp->next = p->next;

	if(p == list){
		list = list->next;
	}
	
	// Delete node
	free(p);
	
	// Return the list
	return list;

}

void save(struct request *list)
{

	struct request * p;

	FILE *pFile;

        pFile = fopen("waiting_list.txt", "w");
	
	if(pFile == NULL)
	{
		printf("Error opening the file\n");
		return;
	}
	for (p =list; p != NULL; p = p->next)
    		fprintf(pFile, "%-s %s %s %s\n", p->email, p->class, p->first,p->last);

	fclose(pFile);

}

void printList(struct request *list){

  struct request *p;

  for (p =list; p != NULL; p = p->next)
    printf("%-50s%-15s%-15s%15s\n", p->email, p->first,p->last,
           p->class);

}

void clearList(struct request *list)
{

	struct request * temp = list;
	struct request * p = list;

	while(p!=NULL) 
	{
    	temp = p;
    	p = p->next;

    	// Delete the previous node
    	free(temp);
	}
}

