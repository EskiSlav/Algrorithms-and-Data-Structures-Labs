#include <stdio.h>
#include "list.h"
#include "stdlib.h"

#ifndef __MAX__
#define MAX 5
#endif


#ifndef __STACK_H__
#define __STACK_H__

void addToStack(double * stack, double elem, int * head, int size);
double removeFromStack(double * stack, int * head);
void printStack(double * stack, int size);

void addToStackList(node ** head, double elem);
double removeFromStackList(node * head);


void apply(double * stack, int * head, char operation);

#endif