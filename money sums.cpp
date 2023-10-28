// author: ahmetG23 @ Github

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int N = 1e6;
int dp[N];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;

    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;

        for(int j = N-1; j >= x; j--) {
            dp[j] = dp[j] || dp[j - x];
        }
    }

    vector<int> ans;
    for(int i = 1; i < N; i++) 
        if(dp[i]) ans.push_back(i);

    cout << ans.size() << '\n';
    for(int x : ans) cout << x << ' ';
}