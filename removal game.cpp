// author: ahmetG23 @ Github

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> v(n), p(n);
    for(ll& x : v) cin >> x;

    for(int i = 0; i < n; i++) // prefix sum
        p[i] = v[i] + (i ? p[i-1] : 0);

    auto sum = [&] (int l, int r) { 
        return p[r] - (l ? p[l-1] : 0); 
    };

    vector dp(n, vector<ll>(n));

    for(int i = 0; i < n; i++)
        dp[i][i] = v[i];

    for(int k = 1; k < n; k++) {
        for(int l = 0; l + k < n; l++) {
            int r = l + k;

            dp[l][r] = max(v[l] + sum(l+1, r) - dp[l+1][r], 
                           v[r] + sum(l, r-1) - dp[l][r-1]);
        }
    }
    cout << dp[0][n-1];
}