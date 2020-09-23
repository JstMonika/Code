#include <iostream>
using namespace std;

int add(int& i, int k)
{
    i = i + 20;
    return i + k;
}

int main()  // caller
{
    int a, b;
    a = 10;
    b = 20;
    
    cout << add(a, b) << endl;
    cout << a << ", " << b << endl;
}

scanf("%c", &ch)
ch = getchar();

printf("%c", ch);
putchar(ch);