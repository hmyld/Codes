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
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int dfs(int a,int b,int x,int y,const vector<vector<int>> &g,vector<vector<int>> &dp){
    dp[x][y] = 1;
    for (int o = 0; o != 4;o++){
        int xx = x + dx[o];
        int yy = y + dy[o];
        if (xx >= 0 && xx < a && yy >= 0&&yy<b&&g[x][y]>g[xx][yy]){
            dp[x][y]=max(dp[x][y],1 + dfs(a, b, xx, yy, g, dp));
        }
    }
    return dp[x][y];
}
int main(){
    int a, b;
    a = read();
    b = read();
    vector<vector<int>> g(a, vector<int> (b));
    for (int i = 0; i != a;i++){
        for (int j = 0; j != b;j++){
            g[i][j] = read();
        }
    }
    vector<vector<int>> dp(a, vector<int> (b,-1));
    int ans = 0;
    for (int i = 0; i != a;i++){
        for (int j = 0; j != b;j++){
            ans=max(ans,dfs(a,b,i, j, g, dp));
        }
    }
    write(ans);
}