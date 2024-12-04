#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main() {
    int n, w;
    cin >> n >> w;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<int> dp(w + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= w; j++) {
            dp[j] = (dp[j] + dp[j - coins[i]]) % mod;
        }
    }
    cout << dp[w] << endl;
    return 0;
}