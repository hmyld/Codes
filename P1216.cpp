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
    int a = read();
    vector<vector<int>> s(a,vector<int>(a,0));
    vector<vector<int>> dp(a,vector<int>(a,0));
    for (int i = 0; i != a;i++){
        for (int j = 0; j <= i;j++){
            s[i][j] = read();
        }
    }
    dp[0][0] = s[0][0];
    for (int i = 1; i != a;i++){
        for (int j = 0; j <= i;j++){
        if(j-1>=0||j!=i){
                dp[i][j] = max(dp[i - 1][j - 1] + s[i][j], dp[i - 1][j] + s[i][j]);
            }else if(j-1<0){
                dp[i][j] = dp[i - 1][j] + s[i][j];
            }else{
                dp[i][j] = dp[i - 1][j - 1] + s[i][j];
            }
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i != a;i++){
        ans = max(ans, dp[a - 1][i]);
    }
    write(ans);
}