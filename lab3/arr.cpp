#include "arr.h"

void printArray(char * arr, int size)
{
    std::cout << "Array: \"";
    for(int i = 0; i < size && arr[i] != '\n'; i++)
    {
        std::cout << arr[i];
    }
    std::cout << "\"" << std::endl;
}

void printArrPart (char * arr, int from, int to)
{
    // std::cout << to - from << ':';
    if ((to - from) % 2 == 0)
        return;
    for(int i = from + 1; i < to - 1; i++)
    {
        std::cout << arr[i];
    }
    std::cout << ' ';
}

void advancedArrPrint(char * arr, int size)
{
    int wBegin = 0;
    int i;
    for(i = 0; i < size && arr[i] != '\n'; i++)
    {
        if(arr[i] == ' ')
        {
            printArrPart(arr, wBegin, i);
            wBegin = i + 1;   
        }
    }
    printArrPart(arr, wBegin, i);
    std::cout << std::endl;
}

char* fillText(int size)
{

    char * text = new char[size];
    char letter;
    for(int i = 0; i < size; i++)
    {
        std::cin.get(letter);
        if(letter == '\n')
        {
            text[i] = letter;
            break;
        }
        else
        {
            text[i] = letter;
        }
    }
    return text;
}

char* insertLetter(char* arr, char letter, int * size)
{
    char * newArr = new char[*size];
    int i = 0;
    while(arr[i] != ' ' && i < *size)
    {
        newArr[i] = arr[i];
        i++;
    }
    newArr[i] = letter;
    while(i < *size)
    {
        newArr[i+1] = arr[i];
        i++;
    }
    *size += 1;
    delete arr;
    return newArr;
}



