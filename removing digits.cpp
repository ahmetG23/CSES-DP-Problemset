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
    
    vector<int> dp(n+1, INF);
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j *= 10) {
            int newNum = i - ((i/j) % 10);

            if(newNum >= 0)
                dp[i] = min(dp[i], dp[newNum]+1);
        }
    }
    cout << dp[n];
}