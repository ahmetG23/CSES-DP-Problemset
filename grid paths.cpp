// author: ahmetG23 @ Github

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int N = 1e6 + 10, INF = 1e9, M = 1e9+7;

int main()
{
    int n;
    cin >> n;
    
    vector<string> grid(n);
    for(string& s : grid) cin >> s;

    if(grid[0][0] == '*') {
        cout << 0;
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(n));

    dp[0][0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '*') continue;
            if(i > 0) (dp[i][j] += dp[i-1][j]) %= M;
            if(j > 0) (dp[i][j] += dp[i][j-1]) %= M;
        }
    }
    cout << dp[n-1][n-1];
}