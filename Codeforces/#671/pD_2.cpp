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
#define devec(v) cout << " > " << #v << ": "; for (auto i : v) cout << i << ' '; cout << endl;
#define devec2(v) cout << " > " << #v << ":\n"; for (auto i : v) { for (auto k : i) cout << ' ' << k; cout << endl; }

const int INF = 1e9;
const int nINF = -1e9;
const ll llINF = 4*1e18;
const int MOD = 1e9+7;

ll& pmod(ll& a, ll b) { a = (a+b) % MOD; return a; }
ll& pmod(ll& a, ll b, ll c) { a = (a+b) % c; return a; }
ll& mmod(ll& a, ll b) { a = (a-b+MOD) % MOD; return a; }
ll& mmod(ll& a, ll b, ll c) { a = (a-b+c) % c; return a; }
ll& tmod(ll& a, ll b) { a = (a*b) % MOD; return a; }
ll mul(ll a, ll b) { return (a*b) % MOD; }
ll mul(ll a, ll b, ll c) { return (a*b) % c; }
ll POW(ll a, ll b) { ll res=1; do { if(b%2) tmod(res,a); tmod(a,a); } while (b>>=1); return res; }
ll FAC(ll a) { ll res = 1; REP1(i, a) tmod(res, i); return res; }

template<typename T1, typename T2>
ofstream operator<<(ofstream& out, pair<T1, T2> a) { cout << a.F << ' ' << a.S; return out; }

int main()
{
    int n;
    cin >> n;
    
    map<int, int> last;
    vec<int> _list(n);
    for (auto &i : _list)
    {
        cin >> i;
        
        last[i]++;
    }
        
    vec<int> tmp = _list;
    sort(al(tmp));
    tmp.resize(distance(tmp.begin(), unique(al(tmp))));
    
    int count = 0;
    vec<int> ans;
    int f = 0, l = tmp.size()-1;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (i % 2 == 0)
            ans.eb(tmp[l--]);
        else
            ans.eb(tmp[f++]);
    }
    
    count = (tmp.size()%2 ? tmp.size()/2 : tmp.size()/2-1);
    
    if (ans.size() % 2)
        reverse(al(ans));
    
    int size = last.size();
    
    for (auto it = last.begin(); it != last.end(); it++)
        if (--it->S == 0) size--;
    
    if (!size and ans.size() % 2 == 0)
    {
        auto it = prev(last.end()); 
        while (it->S == 0) it--;
        
        ans.eb(it->F);
        
        if (!(--it->S)) size--;
        
        count++;
    }
    
    while (size >= 2)
    {
        auto it = last.begin();
        while (it->S == 0) it++;
        
        ans.eb(it->F);
        
        if (!(--it->S)) size--;
        
        it = prev(last.end()); 
        while (it->S == 0) it--;
        
        ans.eb(it->F);
        
        if (!(--it->S)) size--;
            
        count++;
    }
    
    if (size)
    {
        auto it = last.begin();
        while (it->S == 0) it++;
        if (it->F > ans.back())
            count++;
        
        REP(i, it->S)
            ans.eb(it->F);
    }
    
    if (n == 1 or n == 2)
        cout << 0 << endl;
    else
        cout << count << endl;
        
    for (auto i : ans)
        cout << i << ' ';
    cout << endl;
}