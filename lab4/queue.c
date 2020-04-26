#include "queue.h"



int isQueueEmpty(int itemsCount)
{
    if (itemsCount == 0)
        return 1; 
    else 
        return 0;
}

int isQueueFull(int itemsCount)
{
    if (itemsCount == MAX)
        return 1; 
    else 
        return 0;
}
void printQueue(double * queue, int tail, int head, int itemsCount)
{
    if(isQueueEmpty(itemsCount))
        return;
    
    if (tail < head)
        tail += MAX;

    for(int i = head; i < tail + 1; i++)
    {
        printf("%.1f ", queue[i % MAX]);
    }
    printf("\n");
}
void addToQueue(double * queue, double elem, int * tail, int * itemsCount)
{
    if (isQueueFull(*itemsCount))
    {
        printf("%s", "Sorry, queue is Full =(\n");
        return;  
    }
    *tail = (*tail + 1) % MAX;
    queue[*tail] = elem;
    *itemsCount += 1;    
}
void removeFromQueue(double * queue, int * head, int * itemsCount)
{
    if(isQueueEmpty(*itemsCount))
    {
        printf("Nothing to remove. Queue is empty =(\n");
        return;
    }

    *head+=1;
    *itemsCount-=1;
}

// Queue list

void addToQueueList(struct node ** head, double elem)
{
    if(*head == NULL)
    {
        *head = (struct node*)malloc(sizeof(struct node));
        (*head)->x = elem;
        (*head)->prev = NULL;
        (*head)->next = NULL; 
    }
    else
    {
        struct node * temp;
        for (temp = *head; temp->next != NULL; temp = temp->next){ } 
        temp->next = (struct node*)malloc(sizeof(struct node));
        temp->next->prev = temp;
        temp = temp->next;
        temp->x = elem;
        temp->next = NULL;
    }
}

void removeFromQueueList(struct node ** head)
{
    // struct node * temp = (*head)->next;
    if(isListEmpty(*head))
    {
        printf("List is empty! Cannot remove any item!\n");
        return;
    }

    if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    // remove element
    *head = (*head)->next;
    free((*head)->prev);
    (*head)->prev = NULL; 
}