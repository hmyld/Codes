#include <bits/stdc++.h>
using namespace std;

int v[100];

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

bool dfs(int count, int now, int num, const vector<int>& a, int cnt, int len) {
    if (count > cnt) {
        return true;
    }
    if (now == len) {
        return dfs(count + 1, 0, 0, a, cnt, len); 
    }
    int fail = -1;
    for (int i = num; i < a.size(); i++) {
        if (!v[i] && now + a[i] <= len && fail != a[i]) {
            v[i]++;
            if (dfs(count, now + a[i], i + 1, a, cnt, len)) {
                return true;
            }
            fail = a[i];
            v[i] = 0;
            if (now == 0 || now + a[i] == len) {
                return false;
            }
        }
    }
    return false;
}

int main() {
    int n, ans;
    n = read();
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        a[i] = read();
        sum += a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for (int i = 1; i <= sum; i++) {
        if (sum % i != 0) continue; 
        int cnt = sum / i;
        memset(v, 0, sizeof(v));
        if (dfs(1, 0, 0, a, cnt, i)) {
            ans = i;
            break;
        }
    }
    write(ans);
    return 0;
}
