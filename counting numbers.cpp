// author: ahmetG23 @ Github
 
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<int, int>;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
 
string s;
ll dp[20][10][2][2];
 
ll F(int i, int last, bool smaller, bool started) {
    if(i == s.size()) return 1;
    ll& ans = dp[i][last][smaller][started];
    if(ans != -1) return ans;
 
    ans = 0;
 
    int limit = (smaller ? 9 : s[i] - '0');
 
    for(int h = 0; h <= limit; h++) {
        if(started and last == h) continue;
        ans += F(i+1, h, smaller | (h < s[i]-'0'), started | (h > 0));
    }
    return ans;
}
 
ll solve(ll x) {
    if(x == -1) return 0;
    s = to_string(x);
    memset(dp, -1, sizeof dp);
    return F(0, 0, false, false);
}
 
signed main() {
    ll l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l-1);
}