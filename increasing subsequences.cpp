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

    vector<int> v(n);
    for(int& x: v) cin >> x;
    
    vector<int> st;
 
    for (int i = 0; i < n; ++i)
    {
        auto pos = lower_bound(all(st), v[i]);
        if(pos == st.end())
            st.push_back(v[i]);
        else *pos = v[i];
    }
    cout << st.size();
}