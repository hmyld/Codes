#include<bits/stdc++.h>
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
signed main() {
    int a, b;
    vector<int> dsd;
    a = read();
    b = read();
    for (int i = 0; i != a;i++){
        int y = read();
        dsd.push_back(y);
    }
    vector<int> dp(b + 1,0);
    dp[0] = 1;
    for (int j = 0; j != dsd.size();j++) {
        for (int i = b; i >= dsd[j]; i--){
            dp[i] += dp[i - dsd[j]];
        }
    }
    write(dp[b]);
    return 0;
}