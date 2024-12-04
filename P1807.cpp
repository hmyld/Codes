#include <bits/stdc++.h>
using namespace std;
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
unordered_map<int, vector<pair<int, int>>> sto;
void join(int a, int b, int c) {
    sto[a].push_back({b, c});
}
int bfs(int begin, int n) {
    vector<int> dist(n + 1, INT_MIN);
    queue<int> todo;
    dist[begin] = 0;
    todo.push(begin);

    while (!todo.empty()) {
        int temp = todo.front();
        todo.pop();
        for (auto &edge : sto[temp]) {
            int next = edge.first;
            int weight = edge.second;
            if (dist[temp] + weight > dist[next]) {
                dist[next] = dist[temp] + weight;
                todo.push(next);
            }
        }
    }
    return dist[n];
}
int main() {
    int n = read();
    int m = read();
    for (int i = 0; i != m; i++) {
        int u = read();
        int v = read();
        int w = read();
        join(u, v, w);
    }
    int ans = bfs(1, n);
    if(ans==INT_MIN){
        write(-1);
        return 0;
    }
    write(ans);
    return 0;
}