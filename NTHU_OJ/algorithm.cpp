#include <bits/stdc++.h>
using namespace std;

int idx;
int mmap[1500][1500];

void puzzle(int power, int row, int column, int r, int c)
{
    if (power == -1)
        return;
    
    int re = row + (1<<power);
    int ce = column + (1<<power);
    int sr[4] = {re-1, re-1, re, re};
    int sc[4] = {ce-1, ce, ce-1, ce};
    
    int which = 0;
    if (r >= re) which += 2;
    if (c >= ce) which += 1;
    
    sr[which] = r;
    sc[which] = c;
    
    for (int i = 0; i < 4; i++)
    {
        if (i == which)
            continue;
        
        int pr = (i >= 2 ? row + (1<<power) : row);
        int pc = (i % 2 ? column + (1<<power) : column);
        
        puzzle(power-1, pr, pc, sr[i], sc[i]);
    }
    
    for (int i = re-1; i < re+1; i++)
        for (int k = ce-1; k < ce+1; k++)
            mmap[i][k] = idx;
    idx++;
    
    int pr = (which >= 2 ? row + (1<<power) : row);
    int pc = (which % 2 ? column + (1<<power) : column);
    puzzle(power-1, pr, pc, sr[which], sc[which]);
}

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << '\n';
        
        int w, r, c;
        cin >> w >> c >> r;
        idx = 1;
        
        puzzle(w-1, 0, 0, r, c);
        
        mmap[r][c] = -1;
        
        for (int i = 0; i < (1<<w); i++)
            for (int k = 0; k < (1<<w); k++)
                cout << mmap[i][k] << " \n"[k == (1<<w)-1];
    }
}