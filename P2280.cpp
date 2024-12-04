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
int a[5002][5002] = {};
int sum[5002][5002] = {};
void ggg(int c[5002][5002], int sum[5002][5002]) { //横纵坐标 目标矩阵 答案储存矩阵
    for (int i = 0; i != 5002; i++) {
        for (int j = 0; j != 5002; j++) {
            if (i == 0 || j == 0) {
                sum[i][j] = 0; 
            } else {
                sum[i][j] = c[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }
    }
}
int fg(int a, int b, int m, int sum[5002][5002]) {
    int qq;
    qq = sum[a + m][b + m] - sum[a][b + m] - sum[a + m][b] + sum[a][b];
    return qq;
} 
int main() {
    int n, m;
    n = read();
    m = read();
    vector<int> x(n);
    vector<int> y(n);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        x[i] = read();
        y[i] = read();
        p[i] = read();
        a[x[i]][y[i]] += p[i];
    }
    int ans = -10000;
    ggg(a, sum);
    for (int i = 0; i != 5002 - m; i++) {
        for (int j = 0; j != 5002 - m; j++) {
            int temp;
            temp = fg(i, j, m, sum);
            if (temp >= ans) {
                ans = temp;
            }
        }
    }
    write(ans);
    return 0;
}
