#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
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
vector<vector<int>> matrix_mutiply(vector<vector<int>> a, vector<vector<int>>b){
    vector<vector<int>> temp(a.size(),vector<int>(b[0].size()));
    for (int i = 0; i != a.size();i++){
        for (int j = 0; j != b[0].size();j++){
            int restore = 0;
            for (int k = 0; k != a[0].size();k++){
                restore += a[i][k] * b[k][j];
                restore %= mod;
            }
            temp[i][j] = restore;
        }
    }
    return temp;
}
vector<vector<int>> quick_mutiply(vector<vector<int>> a,int b){
    vector<vector<int>> temp(a.size(), vector<int>(a.size(), 0));
    for (int i = 0; i != a.size();i++){
        temp[i][i]++;
    }
    vector<vector<int>> cont = a;
    while(b>0){
        if(b&1){
            temp = matrix_mutiply(temp, cont);
        }
        cont = matrix_mutiply(cont, cont);
        b >>= 1;
    }
    return temp;
}
signed main(){

    vector<vector<int>> aa = { {1, 1}, {1, 0} };
    vector<vector<int>> aaa = { {1}, {1} };
    int n = read();
    if(n<=2){
        write(1);
        return 0;
    }
    aa = quick_mutiply(aa, n - 2);
    aaa = matrix_mutiply(aa, aaa);
    write(aaa[0][0]);
    return 0;
}