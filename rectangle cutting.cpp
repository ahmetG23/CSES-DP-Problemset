// author: ahmetG23 @ Github

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int INF = 1e9;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector dp(n+1, vector<int>(m+1, INF));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i == j) dp[i][j] = 0;

            for(int k = 1; k < i; k++) 
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
    
            for(int k = 1; k < j; k++) 
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
        }
    }
    cout << dp[n][m];
}