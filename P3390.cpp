#include<bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
#define int long long
int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {  // ch 不是数字时
        if (ch == '-') w = -1;       // 判断是否为负
        ch = getchar();              // 继续读入
    }
    while (ch >= '0' && ch <= '9') {  // ch 是数字时，我们输入结束标志为空格或回车。
        x = x * 10 + (ch - '0');      // 将新读入的数字’加’在 x 的后面
        ch = getchar();               // 继续读入
    }
    return x * w;  // 数字 * 正负号 = 实际数值
}

void write(int x) {
    if (x < 0) {  // 判负 + 输出负号 + 变原数为正数
        x = -x;
        putchar('-');
    }
    if (x > 9) write(x / 10);  // 递归，将除最后一位外的其他部分放到递归中输出
    putchar(x % 10 + '0');     // 已经输出（递归）完 x 末位前的所有数字，输出末位
}

vector<vector<int>> matrix_mutiply(vector<vector<int>> a, vector<vector<int>> b){
    vector<vector<int>> temp(a.size(), vector<int>(a.size()));
    for (int i = 0; i != a.size();i++){
        for (int j = 0; j != a.size();j++){
            int mi=0;
            for (int h = 0; h != a.size();h++){
                mi += a[i][h] * b[h][j];
                mi %= mod;
            }
            temp[i][j] = mi;
        }
    }
    return temp;
}
vector<vector<int>> making(const vector<vector<int>> matr, int b){
    vector<vector<int>> temp(matr.size(), vector<int>(matr.size(), 0)); 
    for (int i = 0; i != matr.size(); i++) {
        temp[i][i] = 1;
    }
    vector<vector<int>> inp = matr;
    while (b > 0) {
        if (b & 1) {
            temp = matrix_mutiply(temp, inp);
        }
        inp = matrix_mutiply(inp, inp);
        b >>= 1;
    }
    return temp;
}

signed main() {
    int n, k;
    n = read();
    k = read();
    vector<vector<int>> matr(n, vector<int>(n));
    for (int i = 0; i != n;i++){
        for (int j = 0; j != n;j++){
            matr[i][j] = read();
        }
    }
    matr = making(matr, k);
    for (int i = 0; i != n;i++){
        for (int j = 0; j != n;j++){
            write(matr[i][j]);
            putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}
