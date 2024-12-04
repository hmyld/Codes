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
unordered_map<int, vector<int>> graph;
void join(int u, int v) {
    graph[u].push_back(v);
}
vector<bool> visited;
vector<int> max_path;
int max_mines = 0;
void dfs(int start, const vector<int>& mines, vector<int>& path, int current_mines,int a) {
    visited.assign(a, false);
    visited[start] = true;
    path.push_back(start + 1);
    current_mines += mines[start];
    if (current_mines > max_mines) {
        max_mines = current_mines;
        max_path = path;
    }
    for (int neighbor : graph[start]) {
        if (!visited[neighbor]) {
            dfs(neighbor, mines, path, current_mines, a);
        }
    }
    path.pop_back();
}
int main() {
    int a = read();
    vector<int> mines(a);
    for (int i = 0; i < a; i++) {
        mines[i] = read();
    }
    for (int i = 0; i < a - 1; i++) {
        for (int j = i + 1; j < a; j++) {
            int f = read();
            if (f == 1) {
                join(i, j);
            }
        }
    }
    vector<int> path;
    for (int i = 0; i < a; i++) {
        dfs(i, mines, path, 0, a);
    }
    for (int i = 0; i < max_path.size(); i++) {
        if (i > 0) cout << " ";
        write(max_path[i]);
    }
    cout << endl;
    write(max_mines);
    cout << endl;
    return 0;
}
