#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _NODE
{
	char color[10];
	struct _NODE *next;
} Node;

void insert(Node**, char*, int);

void erase1(Node**, int);

void erase2(Node**, char*);

void reverse(Node**, int, int);

void show(Node **head);
