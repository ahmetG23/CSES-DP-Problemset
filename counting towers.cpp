// author: ahmetG23 @ Github

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int M = 1e9 + 7, N = 1e6 + 5;

int dp[N][2];

void solve() {
    int n;
    cin >> n;
    cout << (dp[n][0] + dp[n][1]) % M << '\n';
}

signed main () {
    ios::sync_with_stdio(0); cin.tie(0);

    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i < N; i++) {
        dp[i][0] = ( 2ll * dp[i-1][0] % M + dp[i-1][1] ) % M;
        dp[i][1] = ( dp[i-1][0] + 4ll * dp[i-1][1] % M ) % M;
    }

    int t; cin >> t;
    while(t--) solve();
}