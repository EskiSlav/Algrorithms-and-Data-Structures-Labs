#include <iostream>

using namespace std;

void func(int num)
{
    if (num == 0) return;
    cout << num % 10;
    func(num / 10);
}

int main() 
{
    int num;
    cin >> num;
    func(num);
    cout << endl;
}