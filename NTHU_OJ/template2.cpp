#include <iostream>
#include <cstring>
using namespace std;
int N, T;
int seq[1005];
bool DP[1005][100005];
// bool able[100005];
int main()
{
    cin >> T;
    while(T--){
        memset(seq, 0, sizeof(seq));
        memset(DP, 0, sizeof(DP));
        cin >> N;
        int Maxnum = 0;
        int totalSum = 0;
        for (int i = 1; i <= N; i++){
            cin >> seq[i];
            Maxnum = max(Maxnum, seq[i]);
            totalSum += seq[i];
        }
        if((totalSum % 2 == 1 )|| Maxnum * 2 > totalSum){
            cout << "No\n";
            continue;
        }else if(Maxnum * 2 == totalSum){
            cout << "Yes\n";
            continue;
        }
        // memset(able, 0, sizeof(able));
        // able[0] = true;
        DP[0][0] = true;
        for (int i = 1; i <= N; i++){
            cout << "Now doing " << seq[i] << endl;
            DP[i][seq[i]] = true;
            
            for (int j = 1; j <= totalSum; j++){
                if(j - seq[i] >= 0 && i > 1){
                    DP[i][j] = DP[i][j] || DP[i - 1][j - seq[i]];
                }
                if(i > 1){
                    DP[i][j] = DP[i][j] || DP[i-1][j];
                }
            }
        }
        // for (int i = 1; i <= N; i++){
        //     for (int j = 1; j <= totalSum; j++)
        //     {
        //         cout << DP[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "\nAns\n";
        cout <<( DP[N][totalSum / 2] == 1 ? "Yes\n" : "No\n");
    }
        return 0;
}