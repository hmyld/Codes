#include<bits/stdc++.h>
using namespace std;
int main() {
    int T, M;
    cin >> T >> M;
    vector<int> dp(T + 1, 0);
    for (int i = 0; i < M; ++i) {
        int time, value;
        cin >> time >> value;
        for (int j = T; j >= time; --j) {
            dp[j] = max(dp[j], dp[j - time] + value);
        }
    }
    cout << dp[T] << endl;
    return 0;
}