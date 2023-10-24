// author: ahmetG23 @ Github

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int N = 1e6 + 10, INF = 1e9, M = 1e9+7;

int main(){
    int n, x;
    cin >> n >> x;
    
    if(x == 0 || n == 0){
        cout << 0;
        return 0;
    }

    vector<int> coins(n);
    for(auto& a: coins)
        cin >> a;

    vector<int> dp(x+1, 0);
    dp[0] = 1;
 
    for(int i = 1; i <= x; i++)
        for(int c: coins)
            if(i - c >= 0)
                (dp[i] += dp[i - c]) %= M;
 
    cout << dp[x];
}