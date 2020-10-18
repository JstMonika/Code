#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> _list(10000000);
    
    int a = 0, b = 0;
    
    clock_t t1 = clock();
    for (int i = 0; i < 10000000; i++)
    {
        a += _list[i];
        b += _list[i];
    }
        
    clock_t t2 = clock();
    
    cout << 1.0 * (t2-t1) << endl;
    
    t1 = clock();
    
    for (int i = 0; i < 10000000; i++)
        a += _list[i];
    for (int i = 0; i < 10000000; i++)
        b += _list[i];
        
    t2 = clock();
    
    cout << 1.0 * (t2-t1) / CLOCKS_PER_SEC << endl;
}