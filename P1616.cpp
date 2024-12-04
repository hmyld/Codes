#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t, m;
    cin >> t >> m;
    vector<int> dp(t + 1, 0);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= t; ++j) {
            dp[j] = max(dp[j], dp[j - a] + b);
        }
    }
    cout << dp[t] << endl;
    return 0;
}