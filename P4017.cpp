#include <bits/stdc++.h>
using namespace std;
const int mode = 80112002;
int read() {
    int x = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}
void write(int x) {
    if (x < 0) {
        x = -x;
        putchar('-');
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
unordered_map<int, vector<int>> chain;
unordered_map<int, int> memo;
vector<int> in_degree;
void join(int u, int v) {
    chain[u].push_back(v);
    return;
}
int dfs(int start) {
    if (chain[start].empty()) {
        return 1;
    }
    if (memo.find(start) != memo.end()) {
        return memo[start];
    }
    int ans = 0;
    for (int i = 0; i < chain[start].size(); i++) {
        ans += dfs(chain[start][i]) % mode;
        ans %= mode;
    }
    memo[start] = ans;
    return ans;
}
int main() {
    int n, m;
    n = read();
    m = read();
    chain.clear();
    memo.clear();
    in_degree.resize(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u = read();
        int v = read();
        join(u, v);
        in_degree[v]++;
    }
    int total_ans = 0;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            total_ans += dfs(i);
            total_ans %= mode;
        }
    }
    write(total_ans);
    putchar('\n');
    return 0;
}
