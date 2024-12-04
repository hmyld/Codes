#include <bits/stdc++.h>
using namespace std;

char* cross(char* s,int b) {
    int a[1001] = {}, c[1001] = {}, d;
    cin >> s;
    cin >> b;
    d = strlen(s);
    for (int i = 0; i < d; i++) {
        a[i] = s[i] - '0';
    }
    int carry = 0;
    c[0]=a[0]*b;
    for (int i = d - 1; i >= 1; i--) {
        int product = a[i] * b + carry;
        c[i] = product % 10;
        product -= c[i];
        carry = product / 10;
    }
    c[0]=c[0]+carry;
    return c;
}int compareHighPrecision(string a, string b) {
    // 去除前导零
    a.erase(0, a.find_first_not_of('0'));
    b.erase(0, b.find_first_not_of('0'));

    // 比较长度
    if (a.length() > b.length()) {
        return 1;
    } else if (a.length() < b.length()) {
        return -1;
    }

    // 长度相同，逐位比较
    for (int i = 0; i < a.length(); i++) {
        if (a[i] > b[i]) {
            return 1;
        } else if (a[i] < b[i]) {
            return -1;
        }
    }

    // 如果完全相同
    return 0;
}

int main() {
    int n;
    cin>>n;
    vector<pair<int, int>> shuzi(n + 1); 
    cin >> shuzi[0].first >> shuzi[0].second;
    for (int i = 1; i <= n; i++) {
        cin >> shuzi[i].first >> shuzi[i].second;
    }
    sort(shuzi.begin()+1, shuzi.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first*a.second<b.first*b.second; 
    });
    vector<string> w(n+1,0);
    for (int i=1; i<=n; i++) {
        char leftall[] = {1};
        for (int j=0;j!=i; j++) { 
            strcpy(leftall, cross(leftall,shuzi[j].first));
        }
        w[i] = cross(leftall,shuzi[i].second); 
    }
    vector<string> ww(n + 1, "0");
    for (int i = 1; i <= n; i++) {
        if (compareHighPrecision(w[i], w[i-1]) > 0) {
            ww[i] = w[i];  // 如果当前结果比上一个大，记录
        } else {
            ww[i] = w[i-1];  // 否则记录之前较大的
        }
    }
    return 0;
}
