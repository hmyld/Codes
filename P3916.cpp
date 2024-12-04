#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> memo;
int read() {
    int x = 0, w = 1;
    char ch = 0;
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
int dfs(int start) {
    if(graph[start].empty()){
        return start;
    }
    if (memo[start] != INT_MIN) {
        return memo[start];
    }
    int ans = start;
    for (int i = 0; i != graph[start].size();i++){
        ans = max(ans, dfs(graph[start][i]));
    }
    memo[start] = ans;
    return ans;
}
int main() {
    int a = read(), b = read();
    graph.resize(a + 1);
    memo.resize(a + 1, INT_MIN);
    for (int i = 0; i != b; i++) {
        int u = read(), v = read();
        graph[u].push_back(v);
    }
    for (int i = 1; i <= a; i++) {
        int ans = dfs(i);
        write(ans);
        putchar(' ');
    }
    putchar('\n');
    return 0;
}
