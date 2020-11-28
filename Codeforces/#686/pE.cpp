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
#define endl '\n'
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
ostream& operator<<(ostream& out, pair<T1, T2> a) { cout << a.F << ' ' << a.S; return out; }

vec<int> pset(1000), Psize(1000);
void initSet(int n) { pset.resize(n); Psize.resize(n); REP1(i, n) { pset[i] = i; Psize[i] = 1; } }
int findSet(int i) { return (pset[i] == i ? i : findSet(pset[i])); }
void unionSet(int i, int k) { Psize[findSet(k)] += Psize[findSet(i)]; pset[findSet(i)] = findSet(k); }
int fsizeSet(int i) {return Psize[findSet(i)]; }

vec<bool> exist;
vec<vec<int>> adj;

pair<int, int> DFS(int p, int k)
{
    exist[k] = true;
    
    for (auto i : adj[k])
        if (i == p)
            continue;
        else if (exist[i])
            return make_pair(i, k);
        else
        {
            auto tmp = DFS(k, i);
            
            if (tmp.F != -1)
                return tmp;
        }
    
    return make_pair(-1, -1);
}

int main()
{
    yccc;
    
    int c;
    cin >> c;
    
    while (c--)
    {
        int n;
        cin >> n;
        
        initSet(n+1);
        
        exist.resize(n+1);
        fill(al(exist), 0);
        adj.clear();
        adj.resize(n+1);
        
        REP(i, n)
        {
            int a, b;
            cin >> a >> b;
            
            adj[a].eb(b);
            adj[b].eb(a);
        }
        
        auto con = DFS(-1, 1);
        
        fill(al(exist), 0);
        
        cout << con << endl;
        
        queue<pair<int, int>> _list;
        for (auto i : adj[con.F])
            for (auto k : adj[i])
                if (k != con.F and k != con.S)
                    _list.emplace(i, k);
        
        for (auto i : adj[con.S])
            for (auto k : adj[i])
                if (k != con.F and k != con.S)
                    _list.emplace(i, k);
                
        exist[con.F] = exist[con.S] = true;
        
        while (_list.size())
        {
            auto cur = _list.front();
            _list.pop();
            
            if (findSet(cur.F) == findSet(cur.S))
                continue;
            if (cur.F == con.F or cur.S == con.F or cur.F == con.S or cur.S == con.S)
                continue;
            
            devec(Psize);
            unionSet(cur.F, cur.S);
            cout << cur << endl;
            devec(Psize);
            
            for (auto i : adj[cur.F])
                if (!exist[i])
                {
                    _list.emplace(cur.F, i);
                    exist[i] = true;
                }
                
            for (auto i : adj[cur.S])
                if (!exist[i])
                {
                    _list.emplace(cur.S, i);
                    exist[i] = true;
                }
        }
        
        int group = -1;
        set<int> left;
        for (auto i : adj[con.F])
            if (i != con.S)
                left.insert(findSet(i));
        
        for (auto i : adj[con.S])
            if (left.find(findSet(i)) != left.end())
                group = findSet(i);
        
        ll ans = n * (n-1);
        
        for (auto i : adj[con.F])
        {
            if (i == con.S)
                continue;
            else if (findSet(i) == group)
                continue;
            else
                ans -= fsizeSet(i) * (fsizeSet(i) + 1) / 2;
        }
        
        devec(pset);
        devec(Psize);
        
        cout << ans << endl;
    }
}