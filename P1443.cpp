#include<bits/stdc++.h>
using namespace std;
int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {  // ch 不是数字时
        if (ch == '-') w = -1;        // 判断是否为负
        ch = getchar();               // 继续读入
    }
    while (ch >= '0' && ch <= '9') {  // ch 是数字时，我们输入结束标志为空格或回车。
        x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面

    ch = getchar();  // 继续读入
    }
    return x * w;  // 数字 * 正负号 = 实际数值
}
void write(int x) {
    if (x < 0) {  // 判负 + 输出负号 + 变原数为正数
        x = -x;
        putchar('-');
    }
    if (x > 9) write(x / 10);  // 递归，将除最后一位外的其他部分放到递归中输出
    putchar(x % 10 + '0');  // 已经输出（递归）完 x 末位前的所有数字，输出末位
}
void bfs(vector<vector<bool>>&used,vector<vector<int>> &ans,int a,int b,int x,int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i != 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < a && ny >= 0 && ny < b && !used[nx][ny]) {
                used[nx][ny] = true;                 
                ans[nx][ny] = ans[cx][cy] + 1;         
                q.push({nx, ny});                   
            }
        }
    }
}
int main(){
    int a, b;
    int x, y;
    a = read();
    b = read();
    x = read();
    y = read();
    x--;
    y--;
    vector<vector<bool>> used(a, vector<bool>(b, false));
    vector<vector<int>> ans(a, vector<int>(b, -1));
    used[x][y] = true;
    ans[x][y] = 0;
    bfs(used, ans, a, b, x, y);
    for (int i = 0; i != a;i++){
        for (int j = 0; j != b;j++){
            write(ans[i][j]);
            if(ans[i][j]==-1){
                cout << "   ";
            }else{
                cout << "    ";
            }
        }
        cout << endl;
    }
    return 0;
}