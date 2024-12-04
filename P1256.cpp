#include<bits/stdc++.h>
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
void bfs(vector<vector<int>>& dist, vector<vector<int>>& arr, int n, int m) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while(!q.empty()){
        pair<int, int> temp = q.front();
        q.pop();
        int x = temp.first;
        int y = temp.second;
        for (auto it = directions.begin(); it!= directions.end(); ++it) {
            int a = it->first;
            int b = it->second;
            int o = a + x;
            int p = b + y;
            if (o >= 0 && o < n && p >= 0 && p < m && dist[o][p] == INT_MAX){
                dist[o][p] = dist[x][y] + 1;
                q.push({o, p});
            }
        }
    }
}

int main() {
    int n = read(); // 行数
    int m = read();
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX)); 
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < m; j++) {
            arr[i][j] = a[j] - '0'; 
        }
    }
    bfs(dist, arr, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0) putchar(' ');
            write(dist[i][j]);
        }
        putchar('\n');
    }

    return 0;
}