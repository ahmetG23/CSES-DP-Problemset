// author: ahmetG23 @ Github

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int M = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    vector<vector<int>> dp(n, vector<int>(m+1));

    for(int& x : v) cin >> x;

    // I am filling dp[0] here
    if(v[0] == 0) 
        for(int i = 1; i <= m; i++) dp[0][i] = 1;
    else 
        dp[0][v[0]] = 1;
    

    for(int i = 1; i < n; i++) 
        for(int j = 1; j <= m; j++) 
            if(v[i] == 0 or v[i] == j) 
                for(int k = max(0, j-1); k <= min(m, j+1); k++)
                    (dp[i][j] += dp[i-1][k]) %= M;

    int ans = 0;
    
    for(int i = 1; i <= m; i++)
        (ans += dp[n-1][i]) %= M;

    cout << ans;
}