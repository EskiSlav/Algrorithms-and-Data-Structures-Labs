#include <stdio.h>
#include "stdlib.h"
#include "list.h"

#ifndef __MAX__
#define MAX 5
#endif

#ifndef __QUEUE_H__
#define __QUEUE_H__

void addToQueue(double * queue, double elem, int * tail, int * itemsCount);
void removeFromQueue(double * queue, int * head, int * itemsCount);
void printQueue(double * queue, int tail, int head, int itemsCount);
int isQueueEmpty(int itemsCount);
int isQueueFull(int itemsCount);

// Queue list

void addToQueueList(struct node ** head, double elem);
void removeFromQueueList(struct node ** head);


#endif