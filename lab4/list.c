#include "list.h"

void printList(struct node * head)
{
    if(isListEmpty(head))
    {
        printf("List is empty!\n");
        return;
    }
    for(struct node * temp = head; temp != NULL; temp = temp->next)
    {
        printf("%.1f ", temp->x);
    }
    printf("\n");
}

int isListEmpty(node * head)
{
    if(head == NULL)
        return 1;
    else 
        return 0;
}
