#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CLASS_LEN 100
#define NAME_LEN 30
#define EMAIL_LEN 50
#ifndef _INCL_GUARD
#define _INCL_GUARD
#endif

struct request{
	char class[CLASS_LEN+1];
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];;

	struct request *next;
};

struct request *load();
void save(struct request *list);
struct request *append(struct request *list);
struct request *delete(struct request *list);
void printList(struct request *list);
void clearList(struct request *list);
int read_line(char str[], int n);