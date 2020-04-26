#include <iostream>

using namespace std;

// TASK 1
double power(double base, int exp) 
{
    if (base == 0 && exp == 0) return 1;
    if (base <= 0) return 0;
    if (exp == 0)  return 1;
    if (exp == 1)  return base;
    return base * power(base, exp-1);
}

// TASK 2
int euclid(int a, int b)
{
    a = abs(a);
    b = abs(b);

    // if (a < b)
    // {
    //     int c = a;
    //     a = b;
    //     b = c;
    // }

    if (b == 0) return a; 
    
    return euclid(b, a % b);
}

//TASK 3
unsigned long fibonachi(unsigned long n)
{
    if (n == 1) return 0;
    if (n == 2) return 1;
    return (unsigned long)fibonachi(n-2) + (unsigned long)fibonachi(n-1);
}

int i = 0;

void move(char from, char to)
{
    i++;
    cout << from << " -> " << to << endl; 
}

void towers(int n, char tower1, char tower2, char temp)
{
    if(n == 0) return;
    towers(n - 1, tower1, temp, tower2);

    move(tower1, tower2);

    towers(n - 1, temp, tower2, tower1);
}

int main()
{
    bool play = true;
    while(play)
    {
        cout << "Choose:\n  1.Power\n  2.Euclid\n  3.Fibonachi\n  4.Towers\n";
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
            double base;
            int exp;
            cout << "Base / Exponent: ";
            cin >> base;
            cin >> exp;
            cout << power(base,exp) << endl << endl;
            break;
        case 2:
            int a, b;
            cout << "Number /  number: "; 
            cin >> a >> b;
            cout << euclid(a,b) << endl << endl;
            break;
        case 3:
            unsigned long num;
            cout << "Number: ";
            cin >> num;
            cout << fibonachi(num) << endl;
            break;
        case 4:
            cout << "Disks: ";
            int disks;
            cin >> disks;
            i = 0;
            towers(disks, 'A', 'C', 'B');
            cout << i << endl;
            break;
        
        default:
            return 0;
            break;
        }
    }
    
}