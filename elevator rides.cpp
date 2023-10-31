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
    
    int n, x;    
    cin >> n >> x;
    
    vector<int> w(n);
    for(auto& x: w) cin >> x;
    
    vector<pii> best(1<<n);
    best[0] = {1, 0};
    
    for(int i = 1; i < (1<<n); i++) {
        best[i] = {n+1, 0};
 
        for(int p = 0; p < 20; p++) if(1<<p & i) {
            auto option = best[i ^(1<<p)];
 
            if(w[p] + option.second <= x) {
                option.second += w[p];
            } else {
                option.first++;
                option.second = w[p];
            }
            best[i] = min(best[i], option);
        }
    }
    cout << best[(1<<n) - 1].first;

}