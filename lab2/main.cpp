
#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <random>


void printArray(int * a, int n);

void insertionSort(int * arr, int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  

        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  

void bubbleSort(int * arr, int n)
{
    int compare = 0, move = 0;
    for(int i = 0; i < n; i++)
    {
        compare++;
        for(int k = i; k < n; k++)
        {
            compare++;
            if(arr[i] > arr[k])
            {
                compare++;
                int num = arr[i];
                arr[i] = arr[k];
                arr[k] = num;
                move += 3;
            }
        }
    }
    std::cout << "Compares: " << compare << ", Moves: " << move << std::endl;

}


void shellSort(int * arr, int n)
{
    
	
    int stepsNum = (int)log2(n) - 1 ;
    int * steps = new int[stepsNum];
    steps[stepsNum-1] = 1;

    for(int i = stepsNum-2;i >= 0; i--)
        steps[i] = 2 * steps[i+1] + 1;

    std::cout << stepsNum << "; ";
    printArray(steps, stepsNum);


    int i, j, increment, temp;
    int move = 0, compare = 0;

    // for(increment = n/2; increment > 0; increment/=2)
    for(int k = 0; k < stepsNum; k++ )
    {   
        // compare++;
        // move++;
        increment = steps[k];
        for(i = increment; i < n; i++)
        {
            // compare++;
            temp = arr[i];
            for(j = i; j >= increment ;j-=increment)
            {
                //perform the insertion sort for this section
                compare++;
                if(temp < arr[j-increment])
                {
                    move++;
                    arr[j] = arr[j-increment];
                }
                else
                {
                    break;
                }
            }
            move++;
            arr[j] = temp;
        }
    }
    std::cout << "Compares: " << compare << ", Moves: " << move << std::endl;

}

void printArray(int * a, int n)
{
    for(int i = 0; i < n; i++)
    {
        std::cout << a[i] << ' '; 
    }
    std::cout << std::endl;
}

int *  fillArray(int n)
{
    int * arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000 + 1;
    } 
    return arr;
}


void call(void (&func)(int* arr , int n), int * arr, int n)
{
    clock_t t = clock();
    (*func)(arr, n);
    std::cout << "Sort time: " << ((double)(clock() - t))/CLOCKS_PER_SEC << std::endl;
}

int main(int argv, char** argc) {
    
    int n = 1000;
    int * arr = fillArray(n);
    std::cout << "1. Bubble Sort\n2. Shell Sort" << std::endl;
    int choice;
    
    std::cin >> choice;

    // printArray(arr, n);
    
    if(choice == 1) call(bubbleSort, arr, n);
    if(choice == 2) call(shellSort, arr, n);
    
    // printArray(arr, n);

    return 0;
}