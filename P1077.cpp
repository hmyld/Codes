#include <bits/stdc++.h>
using namespace std;
const int mod = 1e6 + 7;
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
int main(){
    int n, m;
    n = read();
    m = read();
    vector<int> count(n+1);
    count[0] = 0;
    for (int i = 1; i != n + 1; i++){
        count[i] = read();
    }
    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 1; i != n + 1;i++){
        vector<int> temp(m + 1, 0);
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= count[i] && k <= j;k++) {
                temp[j] = (temp[j] + dp[j - k]) % mod;
            }
        }
        dp = temp;
    }
    write(dp[m]);
    return 0;
}