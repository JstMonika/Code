#include <bits/stdc++.h>
using namespace std;

void func(int n, char start, char end)
{
    if (n == 0)
        return;
    
    char last = 'A' + 'B' + 'C' - start - end;
    
    func(n-1, start, last);
    cout << "move from " << start << " to " << end << '\n';
    func(n-1, last, end);
}

int main()
{
    // suppose A, B, C.
    
    int n;
    char start, end;
    cin >> n >> start >> end;
    
    func(n, start, end);
}