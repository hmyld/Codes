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
int main(){
    int a, b;
    a = read();
    b = read();
    vector<pair<int, int>> cord;
    for (int i = 0; i != b;i++){
        int o = read();
        int p = read();
        cord.push_back({o, p});
    }
    vector<int> dp(a + 1,0);
    for(auto &cord:cord){
        int gsd = cord.first;
        int sd = cord.second;
        for (int i = a; i >= gsd; i--){
            dp[i] = max(dp[i], dp[i - gsd] + gsd * sd);
        }
    }
    write(dp[a]);
    return 0;
}