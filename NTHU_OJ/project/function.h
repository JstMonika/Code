#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Set
{
    Node *head;
    int size;
} Set;

/*****************  NODE  *****************/
Node *create_node(int data);

/*****************  Set  *****************/
Set *create_set();

void insert(Set *set, int data);

Node *erase(Set *set, int data);

int check(Set *set, int data);

int is_empty(Set *set);

void traversal_set(Set *set);