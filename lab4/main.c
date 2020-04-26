#include "stack.h"
#include "queue.h"

int stackMain()
{
    double * stack = (double*)calloc(MAX, sizeof(double));
    int head = 0; 
    // int tail = 0;

    for(int i = 0; i < 8; i++)
        addToStack(stack, rand()%100/10, &head, MAX);

    printStack(stack, head);
    
    removeFromStack(stack, &head);
    printStack(stack, head);
    removeFromStack(stack, &head);
    printStack(stack, head);
    
    addToStack(stack, rand()%100/10, &head, MAX);
    addToStack(stack, rand()%100/10, &head, MAX);
    printStack(stack, head);
    
    return 0;
}

int stackListMain()
{
    node * head = NULL;

    for(int i = 0; i < 8; i++)
        addToStackList(&head, i);

    removeFromStackList(head);

    return 0;
}

int queueMain()
{
    int tail = -1;
    int head = 0;
    int itemsCount = 0;
    double * queue = (double*)calloc(MAX, sizeof(double));

    for(int i = 0; i < 5; i++)
    {
        addToQueue(queue, (double)((i+1)*4)/3, &tail, &itemsCount);
        printQueue(queue, tail, head, itemsCount);
    }

    for(int i = 0; i < 2; i++)
    {
        removeFromQueue(queue, &head, &itemsCount);
        printQueue(queue, tail, head, itemsCount);
    }
    
    addToQueue(queue, 44.1, &tail, &itemsCount);
    printQueue(queue, tail, head, itemsCount);
    addToQueue(queue, 45.1, &tail, &itemsCount);
    printQueue(queue, tail, head, itemsCount);
    addToQueue(queue, 45.1, &tail, &itemsCount);
    printQueue(queue, tail, head, itemsCount);
    return 0;
}

void queueListMain()
{
    node * head = NULL;
    for(int i = 0; i < 5; i++)
    {
        addToQueueList(&head, i*3);
        printList(head);
    }
    for(int i = 0; i < 6; i++)
    {
        removeFromQueueList(&head);
        printList(head);
    }

}

int part2Main()
{
    double * stack = (double*)calloc(MAX, sizeof(double));
    int head = 0; 
    char input[100] = "";
    double n = -1;
    char * rest;

    while(1)
    {
        printf("Enter: ");
        scanf("%s", &input);
        n = strtod(input, &rest);
        
        // printf("Number: %lf   Rest string: %s\n Input: %s\n ", n, rest, input);
        
        if (*rest == '\0')
        {
            addToStack(stack, n, &head, MAX);
        }
        else if(rest[0] == 'e')
        {
            return 1;
        }
        else if(*rest != '\0')
        {
            apply(stack, &head, *rest);
        }
        printStack(stack, head);
        // if ( n < 1)
        // {
        //     char operation = "";
        //     scanf("%s", &operation);  // eats a character off the buffer
        //     apply(stack, &head, operation);
        // }
        // else
        // {
        //     addToStack(stack, n, &head, MAX);
        //     printStack(stack, head);
        // }
        
    }
    return 0;
}

int main() {
    // stackMain();
    // stackListMain();
    // queueMain();
    // queueListMain();
    part2Main();
    return 0;
}
