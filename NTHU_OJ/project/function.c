#include "function.h"

/*****************  NODE  *****************/
Node *create_node(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

/*****************  SET  *****************/
Set *create_set()
{
    Set *set = (Set *)malloc(sizeof(Set));
    set->head = NULL;
    set->size = 0;
    return set;
}

void insert(Set *set, int data)
{
    if (check(set, data))
        return;

    Node *node = create_node(data);

    /* Todo */
    
    if (set->head == NULL)
    {
        set->head = node;
        set->size++;
        
        return;
    }
    
    Node* cur = set->head;
    Node* prev = NULL;
    while (cur != NULL && cur->data < node->data)
    {
        prev = cur;
        cur = cur->next;
    }
    
    node->next = cur;
    
    if (prev != NULL)
       prev->next = node;
    else
        set->head = node;
    
    set->size++;
    
    return;
}

Node *erase(Set *set, int data)
{
    if (!check(set, data))
        return NULL;

    Node *tmp = set->head;
    Node* prev = NULL;
    /* Todo*/
    
    while (tmp->data != data)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    
    if (prev == NULL)
    {
        set->head = tmp->next;
    }
    else
    {
        prev->next = tmp->next;
    }
    
    return tmp;
}

int check(Set *set, int data)
{
    if (is_empty(set))
        return 0;

    Node *tmp = set->head;
    /* Todo */
    
    while (tmp != NULL)
    {
        if (tmp->data == data)
            return 1;
            
        tmp = tmp->next;
    }
        
    return 0;
}

int is_empty(Set *set)
{
    return set->size == 0 ? 1 : 0;
}

void traversal_set(Set *set)
{
    // 1 2 3
    Node* head = set->head;
    
    if (head == NULL)
        printf("Set is empty\n");
    else
    {
        while (head != NULL)
        {
            if (head != set->head)
                printf(" ");
            
            printf("%d", head->data);
            
            head = head->next;
        }
        printf("\n");
    }
    
    return;
}