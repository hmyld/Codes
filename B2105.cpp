#include<bits/stdc++.h>
using namespace std;
#define int long long
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
vector<vector<int>> mm(vector<vector<int>> a,vector<vector<int>>b,int h,int j,int k){
    vector<vector<int>>temp(h, vector<int>(k));
    for (int i = 0; i != h;i++){
        for (int o = 0; o!=k;o++){
            int mi=0;
            for (int p = 0; p != j;p++){
                mi += a[i][p] * b[p][o];
            }
            temp[i][o] = mi;
        }
    }
    return temp;
}
signed main(){
    int h, j, k;
    h = read();
    j = read();
    k = read();
    vector<vector<int>> a(h, vector<int>(j));
    vector<vector<int>> b(j, vector<int>(k));
    for (int i = 0; i != h;i++){
        for (int g = 0; g != j;g++){
            a[i][g] = read();
        }
    }
    for (int i = 0; i != j;i++) {
        for (int g = 0; g != k;g++){
            b[i][g] = read();
        }            
    }
    vector<vector<int>> ans = mm(a, b, h, j, k);
    for (int i = 0; i != h;i++){
        for (int o = 0; o != h;o++){
            write(ans[i][o]);
            putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}