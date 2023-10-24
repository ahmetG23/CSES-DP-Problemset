// author: ahmetG23 @ Github

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> cost(n), pages(n), dp(x+1);

    for(int& x : cost) cin >> x;
    for(int& x : pages) cin >> x;


    for(int j = 0; j < n; j++)
        for(int i = x; i >= 1; i--)  
            if(i >= cost[j])
                dp[i] = max(dp[i], pages[j] + dp[i - cost[j]]);

    cout << dp[x];
}