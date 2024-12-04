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
void dfs(int a/*数字*/,int b/*当前深度*/,vector<bool>& used,vector<int>&j){
    if(b==a+1){
        for (int i = 1; i != b;i++){
            cout << "    ";
            write(j[i]);
        }
        cout << endl;
        return;
    }
    if(b<=a){
        for (int i = 1; i <= a; ++i) {
        if (!used[i]) {
            j[b] = i;
            used[i] = true;
            dfs(a, b+1,used, j);
            used[i] = false;
        }
    }
}
}
int main(){
    int i;//什么数
    i = read();
    vector<int> j(i+1);
    vector<bool> used(i+1,false);
    dfs(i, 1, used, j);
    return 0;
}