// author: ahmetG23 @ Github

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int N = 5005;

int n, m, dp[5005][5005];
string s, t;

signed main()
{
    cin >> s >> t;
    n = s.size(); m = t.size();
    
    for(int i = 0; i <= n; i++)
        dp[i][0] = i;
    for(int i = 0; i <= m; i++)
        dp[0][i] = i;
 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) {
            dp[i][j] = min({
                            dp[i-1][j-1] + (s[i-1] != t[j-1]), 
                            dp[i-1][j] + 1,
                            dp[i][j-1] + 1
                          });
        }
    }
    cout << dp[n][m];
}