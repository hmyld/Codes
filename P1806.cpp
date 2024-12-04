#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int, int> record;
int dfs(int a, int t) {
    if (a == 0) return 1;
    if (t > a) return 0;
    if (record.find(a * 1000 + t) != record.end()) {
        return record[a * 1000 + t];
    }
    int res = dfs(a - t, t + 1) + dfs(a, t + 1);
    record[a * 1000 + t] = res;
    return res;
}
signed main() {
    int a;
    cin >> a;
    cout << dfs(a, 1) - 1 << endl;
    return 0;
}
