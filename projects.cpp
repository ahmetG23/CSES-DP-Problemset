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

    vector<int> a(n), b(n), c(n);
    map<int, int> compress;

    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        b[i]++;
        compress[a[i]]; 
        compress[b[i]];
    }

    int new_val = 0;

    for(auto& x : compress)
        x.second = new_val++;

    vector<vector<pii>> jobs(new_val);

    for(int i = 0; i < n; i++) 
        jobs[compress[b[i]]].push_back({compress[a[i]], c[i]});
    

    vector<ll> dp(new_val);
    for(int i = 0; i < new_val; i++) {
        if(i > 0)
            dp[i] = dp[i-1];

        for(auto j : jobs[i]) 
            dp[i] = max(dp[i], dp[j.first] + j.second);
   } 
   cout << dp.back();
}