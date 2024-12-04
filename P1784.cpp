#include<bits/stdc++.h>
using namespace std;
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
int dfs(int dpt/*当前深度*/,int m/*最大深度=棋盘边长*/,vector<bool>&a,vector<bool>&tg1,vector<bool>&tg2,vector<vector<int>> &ans,vector<int>&currsolution,int &total){
    if (dpt > m){
        total++;
        if (ans.size() < 3) {
            ans.push_back(currsolution);
        }
    }
    for (int i = 1; i <= m;i++){
        if(!a[i]&&!tg1[dpt-i+m-1]&&!tg2[dpt+i]){
            a[i] = true;
            tg1[dpt - i + m - 1] = true;
            tg2[dpt + i] = true;
            currsolution.push_back(i);
            dfs(dpt + 1, m, a, tg1, tg2, ans, currsolution, total);
            a[i] = false;
            tg1[dpt - i + m - 1] = false;
            tg2[dpt + i] = false;
            currsolution.pop_back();
        }
    }
    return total;
}
int main(){
    int m;
    m = read();
    vector<bool> a(m, false);
    vector<bool> tg1(2*m+1, false);
    vector<bool> tg2(2*m+1, false);
    vector<vector<int>> ans;
    vector<int> currsolution;
    int anss = 0;
    anss=dfs( 1, m, a, tg1, tg2, ans, currsolution, anss);
    for (int i = 0; i != 3;i++){
        for (int j = 0; j != m;j++){
            write(ans[i][j]);
            cout << " ";
        }
        cout << endl;
    }
    write(anss);
    return 0;
}