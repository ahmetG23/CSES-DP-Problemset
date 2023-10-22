// author: ahmetG23 @ Github

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int N = 1e6 + 10, M = 1e9 + 7;


signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n;
	cin >> n;

	vector<int> dp(n+1);
	dp[0] = 1;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= 6; j++)  if(i >= j) {
			(dp[i] += dp[i - j]) %= M;
		}
	}
	cout << dp[n];
}