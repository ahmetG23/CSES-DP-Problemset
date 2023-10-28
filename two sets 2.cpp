// author: ahmetG23 @ Github
 
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<int, int>;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
 
const int N = 500 * 501, M = 1e9 + 7;

int mul(int a, int b) {
    return 1ll * a * b % M;
}
int mexp(int a, int b) {
    int k = 1;
    while(b > 0) {
        if(b & 1) k = mul(k, a);
        a = mul(a, a);
        b >>= 1;
    }
    return k;
}
int dvd(int a, int b) {
    return mul(a, mexp(b, M-2));
}

int dp[N];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
 
    int n;
    cin >> n;
     
    int sum = n * (n+1) / 2;   

    if(sum % 2) {
        cout << 0;
        return 0;
    } 

    dp[0] = 1;
 
    for(int i = 1; i <= n; i++) 
        for(int j = sum; j >= i; j--) 
            (dp[j] += dp[j - i]) %= M;
 
    cout << dvd(dp[sum/2], 2);
}
