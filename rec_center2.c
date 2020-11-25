#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CLASS_LEN 100
#define NAME_LEN 30
#define EMAIL_LEN 50

struct request{
	char class[CLASS_LEN+1];
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];;

	struct request *next;
};

struct request *add(struct request *list);
void printList(struct request *list);
void clearList(struct request *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct request *wait_list = NULL;  
  printf("Operation Code: a for adding to the ordered list,"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': wait_list = add(wait_list);
		break;
      case 'p': printList(wait_list);
                break;
      case 'q': clearList(wait_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

// Function to add new requests to list
struct request *add(struct request *list){
  struct request *p, *prev;

  // Allocate memory to new request dynamically
  struct request *new = (struct request*) malloc(sizeof(struct request));

  // prompt user to enter e-mail address, class, first name, last name
  printf("Enter e-mail address: ");
  scanf("%s", new->email);
  printf("Enter class: ");
  scanf("%s", new->class);
  printf("Enter first name: ");
  scanf("%s", new->first);
  printf("Enter last name: ");
  scanf("%s", new->last);
  
  new->next = NULL;
  
  // if list is empty, add new request to list as starting node
  if(list == NULL){
      list = new;
      return list;
  }

  // if list contains only one request
  else if(list->next == NULL){

      // if new request class is less than current request class, then add it as starting node
      if(strcmp(new->class, list->class) < 0){
          new->next = list;
          list = new;
      }

      // if new request class is greater than current request class, then add it as ending node
      else if(strcmp(new->class,list->class) > 0){
          list->next = new;
      }

      // if new request class is equal to current request class
      else if(strcmp(new->class, list->class) == 0){
          if(new->last < list->last){
              new->next = list;
              list = new;
          }
          else{
                list->next = new;
          }
      }   
      return list;
  }
  
  prev = p = list;

  // if list contains more than one node
  while(strcmp(new->class,p->class) > 0 && p->next!= NULL){
      prev = p;
      p = p->next;
  }
  
  // if new request class is greater than current request class, 
  if(strcmp(new->class,p->class) > 0){
      new->next = p->next;
      p->next = new;
  }

  //if new request is less than first node, then new request is to be added as first node
  else if(strcmp(new->class,p->class) < 0 && p == list){
      new->next = p;
      list = new;
  }

  // if new request class is less than current request class 
  else if(strcmp(new->class,p->class) < 0){
          new->next = p;
          prev->next = new;
  }

  // if new request class is equal to current request class
  else if (strcmp(new->class,p->class) == 0){
      while(strcmp(new->last, p->last) > 0 && strcmp(new->class,p->class) == 0 && p->next!= NULL){
          prev = p;
          p = p->next;
      }
      if(strcmp(new->last, p->last) > 0){
          p->next = new;
      }
      else{
          prev->next = new;
          new->next = p;
      }
  }
  return list;
}


/**********************************************************
 * printList: print the data  in the linked list passed   *
 * in as parameter                                        *
 **********************************************************/


void printList(struct request *list){

  struct request *p;

  printf("\nEmail\t\t\t\t\t\tFirst Name\tLast Name\t\t"
         "class\n");
  for (p =list; p != NULL; p = p->next)
    printf("%-50s%-15s%-15s%15s\n", p->email, p->first,p->last,
           p->class);

}

/*************************************************************
 * clearList: release the memory in the linked list passed   *
 * in as parameter                                           *
 *************************************************************/


void clearList(struct request *list)
{

 
  struct request *p;

  while(list!=NULL)
  {
         p = list;
         list = list->next;
         if(p!=NULL)
            free(p);
  }


}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}

