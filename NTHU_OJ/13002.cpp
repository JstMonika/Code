#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

int main()
{
    ll c;
    
    ll alpha[10000], beta[10000];
    
    alpha[0] = 0;
    alpha[1] = 1;
    beta[0] = 1;
    beta[1] = 0;
    
    for (int i = 2; i < 10000; i++)
    {
        alpha[i] = alpha[i-1] + alpha[i-2];
        beta[i] = beta[i-1] + beta[i-2];
    }
    
    while (cin >> c)
    {
        if (c == 0 or c == 1)
        {
            cout << "0" << endl;
            continue;
        }
        
        ll ans = 0;
        
        for (int i = 1; i < 10000; i++)
        {
            if (alpha[i] + beta[i] > c)
                break;
            
            if ((c - beta[i]) % alpha[i] == 0)
                ans = (c - beta[i]) / alpha[i];
        }
        
        cout << ans << endl;
    }
}