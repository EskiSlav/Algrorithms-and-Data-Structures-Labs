#include <iostream>

struct Node {
    char letter;
    Node * next;
    Node * prev;
};

void addTail(Node * head, char letter);
void addHead(Node ** head, char letter);
void insertList(Node * head, char letter, int place);

void createList(Node* head);
void advancedPrint(Node* head);
void printList(Node* head);
void printPart(Node* wBegin, int size);
void printListReverse(Node * head);