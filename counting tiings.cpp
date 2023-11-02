// author: ahmetG23 @ Github
 
#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int dp[1000][1<<10];
int n, m;

vector<int> cand;

// If two adjacent bits are both 1, we can put a 2x1 block on them.
// This function tries to put 2x1 blocks on those bits and generate 
// all possible bitmasks.
void gen_all(int k, int i = 0) { 
    if(i == n) {
        cand.push_back(k);
        return;
    }

    gen_all(k, i+1);

    if((1<<i) & k and (1<<(i+1)) & k) 
        gen_all(k ^ (1<<i | 1<<(i+1)), i+1);
}

// Checks whether the given bitmask is valid for being first column
bool valid(int s) {
    int streak = 0;
    for(int i = 0; i < n; i++) {
        if(s & (1<<i)) {
            if(streak % 2) return false;
            streak = 0;
        }
        else streak++;
    }
    return streak % 2 == 0;
}

signed main() {
    cin >> n >> m;

    // fill dp[0]
    for(int s = 0; s < (1<<n); s++)
        if(valid(s)) 
            dp[0][s] = 1;

    for(int i = 0; i < m-1; i++) {
        for(int s = 0; s < 1<<n; s++) {
            // k is the complementary of s
            int k = ~s & ((1<<n) - 1);

            cand.clear();
            gen_all(k);

            for(int x : cand)
                (dp[i+1][x] += dp[i][s]) %= M;
        }
    }
    cout << dp[m-1][0];
}
