#include "list.h"

void createList(Node * head)
{
    char letter;
    std::cin.get(letter);
    Node * cursor = head;
    cursor->letter = letter;
    cursor->next = NULL;
    cursor->prev = NULL;
    std::cin.get(letter);
    while (letter != '\n'){
        cursor->next = new Node;
        cursor->next->prev = cursor;
        cursor = cursor->next;
        cursor->letter = letter;
        cursor->next = NULL;
        std::cin.get(letter);
    } 
}

void printList(Node * head)
{
    std::cout << "List: \"";
    for(Node * temp = head; temp != NULL && temp->letter != '\n'; temp = temp->next)
        std::cout << temp->letter;

    std::cout << "\"" << std::endl;
}

void printListReverse(Node * head)
{
    Node * temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    
    std::cout << "Reversed List: \"";
    while(temp != NULL)
    {
        std::cout << temp->letter;
        temp = temp->prev;
    }
    std::cout << "\"" << std::endl;
}

void printPart(Node * wBegin, int size)
{
    if(size % 2 == 0)
        return;
    Node * temp = wBegin->next;
    // std::cout << ".!wBegin!.\n";
    for(int i = 0; i < size - 2 ; i++)
    {
        std::cout << temp->letter;
        temp = temp->next;
    }
    std::cout << ' ';
}


void advancedPrint(Node * head)
{
    Node * wBegin = head;
    Node * temp   = head;
    int wordLength = 0;
    while(temp != NULL)
    {
        if(temp->letter != ' ')
        {
            wordLength++;
        }
        else
        {
            printPart(wBegin, wordLength);
            wBegin = temp->next;
            wordLength = 0;
        }
        temp = temp->next;
    }
    if(wordLength > 0)
        printPart(wBegin, wordLength);

    std::cout << std::endl;
}

void insertList(Node * head, char letter, int place)
{
    Node * temp = head;
    if (place == 1)
    {
        addHead(&head, letter);
        return;
    }
    else if (place < 0)
    {
        std::cout << "Invalid place";
        return;
    }

    for(int i = 0; i < place-2 && temp != NULL; i++)
        temp = temp->next;
    
    if(temp != NULL)
    {
        Node * nNode = new Node;
        nNode->letter = letter;
        nNode->next = temp->next;
        nNode->prev = temp;
        temp->next->prev = nNode;
        temp->next = nNode;
    }
    
}

void addTail(Node * head, char letter)
{
    Node * temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    Node * nNode = new Node;
    nNode->next = NULL;
    nNode->letter = letter;
    nNode->prev = temp;
    temp->next = nNode;
}

void addHead(Node ** head, char letter)
{
    Node * nNode = new Node;
    (*head)->prev = nNode;
    nNode->letter = letter;
    nNode->next = (*head);
    nNode->prev = NULL;
    (*head) = nNode;
}

void printListSize(Node * head)
{
    int size = 0;
    for(Node * temp = head; temp != NULL; temp = temp->next)
        size += sizeof(temp);
    std::cout << "List size: " << size << std::endl; 
}