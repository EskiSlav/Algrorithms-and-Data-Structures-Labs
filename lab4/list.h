#include <stdio.h>

#ifndef __LIST_H__
#define __LIST_H__

typedef struct node
{
    double x;
    struct node * next;
    struct node * prev;
} node; 

void printList(node * head);
int isListEmpty(node * head);

#endif