#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "request.h"
#include "readline.h"


int main(void){

    char code; 
    struct request *wait_list = load(); 

    printf("Operation Code: d for deleting from the list, a for appending to the list,"
        ", p for printing the list; q for quit.\n");
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')   /* skips to end of line */
            ;
        switch (code) {
            case 'd': wait_list = delete(wait_list);
            break;
            case 'a': wait_list = append(wait_list);
            break;
            case 'p': printList(wait_list);
            break;
            case 'q': save(wait_list);
            clearList(wait_list);
            return 0;
            default:  printf("Illegal code\n");
        }
        printf("\n");
    }
}