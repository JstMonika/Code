#include <bits/stdc++.h>
using namespace std;

template<typename T> using vec = vector<T>;

int dp[1010][100010];

int main()
{
    int c;
    cin >> c;
    
    for (int i = 0; i < 1010; i++)
        dp[i][0] = 0;
    for (int i = 0; i < 100010; i++)
        dp[0][i] = 0;
    
    while (c--)
    {
        int n, sum = 0;
        cin >> n;
        
        vec<int> _list(n);
        for (auto &i : _list)
        {
            cin >> i;
            sum += i;
        }
        
        if (sum % 2)
        {
            cout << "QAQ\n";
            continue;
        }
        
        for (int i = 1; i <= n; i++)
            for (int k = 1; k <= sum/2; k++)
            {
                if (_list[i-1] > k)
                    dp[i][k] = dp[i-1][k];
                else
                    dp[i][k] = max(dp[i-1][k - _list[i-1]] + _list[i-1], dp[i-1][k]);
            }
            
        cout << (dp[n][sum/2] == sum/2 ? "Yes\n" : "QAQ\n");
    }
}