#include"function.h"
#include<stdio.h>

void insert(Node** head, char*buf, int num)
{ 
    //creat a new node 
    Node* start = *head;
    Node* prev = NULL;
    while(start!=NULL && num>=0)
    { 
        prev=start;
        start=start->next;
        num--;
    }
    Node* temp=(Node*)malloc(sizeof(Node));//new a node
    memset(temp->color,'\0',sizeof(temp->color));
    strcpy(temp->color,buf);
    printf("add %s\n",buf);
    temp->next=start;

    if(prev!=NULL)
        prev->next = temp;

    else *head=temp;
}

void erase1(Node** head, int num)//deleting last one 
{ 
    Node* start = *head;
    Node* prev = NULL;
    while(start!=NULL && num>0)
    { 
        prev=start;
        start=start->next;
        num--;
    }
    prev->next=start->next;
    printf("remove %s\n",start->color);
    free(start);

}

void erase2(Node** head, char*buf)//頭尾、連續
{ 
    Node* tmp = (*head)->next;
    free(*head);
    head = (*head)->next;
    
    Node* start = *head;
    Node* prev = NULL;
    while(start!=NULL)
    {
        if (strcmp(start->color, buf) != 0)
        {
            prev = start;
            start = start->next;
            
            continue;
        }
             
        if(prev == NULL)
        { 
            // prev->next=start->next;
            Node* tmp = start->next;
            printf("remove a %s\n",start->color);
            free(start);
            start = tmp;
            prev=NULL;
            
            *head = start;
        }
        else
        { 
            prev->next=start->next;
            printf("remove a %s\n",start->color);
            free(start);
            // prev=start;
            start=prev->next;
        }
    }
}

void reverse(Node** head, int num1, int num2)
{ 

}
