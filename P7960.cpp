#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
const int K = 10000001;
vector<int> p(K,0);
vector<int> next_free(K);
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
bool con7(int x) {
    while (x) {
        if (x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}
int main(){
    int a;
    a = read();
    vector<int> aim(a);
    vector<int> ans(a);
    for (int i = 0; i < a;i++){
        aim[i] = read();
    }
    for (int i = 1; i < K; ++i) {
        if (con7(i)) { 
            for (int j = i; j < K; j += i) {
                p[j]++;
            }
        }
    }
    int last_free = K;  // 初始时无未标记数字
    for (int i = K - 1; i >= 0; --i) {
        if (!p[i]) {
            last_free = i;
        }
        next_free[i] = last_free;
    }
    for (int i = 0; i < a; i++) {
        if(p[aim[i]]) {
            ans[i] = -1;
        } else{
            ans[i] = next_free[aim[i] + 1];
        }
    }
    for (int i = 0; i != a;i++){
        write(ans[i]);
        cout << endl;
    }
    return 0;
}