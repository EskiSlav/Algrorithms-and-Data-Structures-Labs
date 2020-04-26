#include "stack.h"
#include "list.h"
//---Array-----------------------------

void printStack(double * stack, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%.1f ", stack[i]);
    }
    printf("\n");
}

void addToStack(double * stack, double elem, int * head, int size)
{
    if (*head == size)
    {
        printf("%s", "Stack overflow!\n");
        return;
    }
    stack[*head] = elem;
    *head +=1;
}

double removeFromStack(double * stack, int * head)
{
    if(*head < 1)
    {
        printf("%s", "Stack underflow!\n");
        return -1;
    }
    *head -= 1;
    // printStack(stack, *head);
    return stack[*head];
}

void apply(double * stack, int * head, char operation)
{
    if (*head < 2)
    {
        printf("%s\n", "Not enough items!");
        return;
    }
    double n2 = removeFromStack(stack, head);
    double n1 = removeFromStack(stack, head);
    

    printf("Nums: %f %f\n", n1, n2);
    if(operation == '+')
    {
        addToStack(stack, n1+n2, head, MAX);
    }
    else if(operation == '-')
    {
        addToStack(stack, n1-n2, head, MAX);
    }
    else if(operation == '*')
    {
        addToStack(stack, n1*n2, head, MAX);
    }
    else if(operation == '/')
    {
        addToStack(stack, n1/n2, head, MAX);
    }
}

//---List-----------------------------

// void printStackList(node * head)
// {
//     for(struct node * temp = head; temp != NULL; temp = temp->next)
//     {
//         printf("%.1f ", temp->x);
//     }
//     printf("\n");
// }

void addToStackList(node ** head, double elem)
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
    // printStackList(*head);
}

double removeFromStackList(node * head)
{
    node * temp;
    for (node * temp = head; temp->next != NULL; temp = temp->next){ }
     
    temp->prev->next = NULL;
    return temp->x;
}
