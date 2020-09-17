#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T> using vec = vector<T>;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;

#define yccc ios_base::sync_with_stdio(false), cin.tie(0)
#define al(a) a.begin(),a.end()
#define F first
#define S second
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define eb emplace_back
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define debug(x) cout << " > " << #x << ": " << x << endl;

const int INF = 1e9;
const int nINF = -1e9;
const ll llINF = 4*1e18;
const int MOD = 1e9+7;

ll pmod(ll& a, ll b) { a = (a+b) % MOD; return a; }
ll pmod(ll& a, ll b, ll c) { a = (a+b) % c; return a; }
ll mmod(ll& a, ll b) { a = (a-b+MOD) % MOD; return a; }
ll tmod(ll& a, ll b) { a = (a*b) % MOD; return a; }
ll POW(ll a, ll b) { ll res=1; do { if(b%2) tmod(res,a); tmod(a,a); } while (b>>=1); return res; }

int main()
{
    yccc;
    
    int c;
    cin >> c;
    
    while (c--)
    {
        int n, m;
        cin >> n >> m;
        
        vec< vec<char> > _list(n, vec<char>(m));
        
        REP(i, n)
            REP(k, m)
                cin >> _list[i][k];
                
        int count = 0;
        for (int i = 0; i < m-1; i++)
            if (_list[n-1][i] == 'D')
                count++;
        for (int i = 0; i < n-1; i++)
            if (_list[i][m-1] == 'R')
                count++;
                
        cout << count << endl;
    }
}