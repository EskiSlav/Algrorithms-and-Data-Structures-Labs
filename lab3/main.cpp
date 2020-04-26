
#include "list.h"
#include "arr.h"


void iclear(const char * message)
{
    if (message != "")
        std::cout << message;
    std::cin.clear();
    std::cin.ignore(10000,'\n');
}

int main(int argc, char ** argv)
{
    int choice;
    std::cout << "1.Array, \n2.List: \n";
    if(!(std::cin >> choice))
        iclear("Please, enter numbers only\n");
    else
    {
        switch (choice)
        {
            //____________________________ARRAY________________________
        case 1:
            int size;
            std::cout << "Size: ";
            if(!(std::cin >> size))    
                iclear("Please, enter numbers only!\n");
            else
            {
                iclear("");
                char * text = fillText(size);
                printArray(text, size);
                while(true)
                {
                    std::cout << "1, 2, 3: ";
                    if(!(std::cin >> choice))
                        iclear("Please enter numbers only");
                    switch (choice)
                    {
                    case 1:
                        printArray(text, size);
                        break;
                    case 2:
                        advancedArrPrint(text, size);
                        break;
                    case 3:
                        char letter;
                        std::cout << "Enter letter: ";
                        std::cin >> letter;
                        iclear("");
                        text = insertLetter(text, letter , &size);
                        std::cout << "Size: " << size << std::endl;
                        break;
                    }
                }
            }
            break;

        // ______________________________LIST______________________
        case 2:
            
            char letter;
            Node * head = new Node;

            iclear("");
            std::cout << "Fill list: ";
            createList(head);
            while(true)
            {
                std::cout << "1.Print List\n2.Print Reverse\n3.Print Advanced\n4.Insert\n5.Add Head\n6.Add Tail\n";
            
                if(!(std::cin >> choice))
                    iclear("Please enter numbers only");
                
                switch (choice)
                {
                case 1:
                    printList(head);
                    break;
                case 2:
                    printListReverse(head);
                    break;
                case 3:
                    advancedPrint(head);
                    break;
                case 4:
                    int place;
                    std::cout << "Place: ";
                    std::cin >> place;
                    std::cout << "Letter: ";
                    std::cin >> letter;
                    iclear("");
                    insertList(head, letter, place);
                    break;
                case 5:
                    std::cout << "Letter to insert: ";
                    std::cin >> letter;
                    iclear("");
                    addHead(&head, letter);
                    break;
                case 6:
                    std::cout << "Letter to insert: ";
                    std::cin >> letter;
                    iclear("");
                    addTail(head, letter);
                    break;
                default:
                    return 0;
                }
            }    
            break;
        }
    }
    
    
    return 0;
}

