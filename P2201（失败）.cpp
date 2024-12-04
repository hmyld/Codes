#include <bits/stdc++.h>
using namespace std;

int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') { // ch 不是数字时
        if (ch == '-') w = -1;       // 判断是否为负
        ch = getchar();              // 继续读入
    }
    while (ch >= '0' && ch <= '9') { // ch 是数字时，我们输入结束标志为空格或回车
        x = x * 10 + (ch - '0');     // 将新读入的数字加在 x 的后面
        ch = getchar();              // 继续读入
    }
    return x * w;                    // 数字 * 正负号 = 实际数值
}

void write(int x) {
    if (x < 0) { // 判负 + 输出负号 + 变原数为正数
        x = -x;
        putchar('-');
    }
    if (x > 9) write(x / 10); // 递归，将除最后一位外的其他部分放到递归中输出
    putchar(x % 10 + '0');    // 输出末位
}

class editor {
private:
    vector<int> a;  
    vector<int> sto;
    int n = 0;       
    void updateStoFrom(int pos) {
        if (pos < a.size()) {
            if (pos == 0) {
                sto[0] = a[0];
                pos++;
            }
            for (int i = pos; i < a.size(); i++) {
                sto[i] = sto[i - 1] + a[i];
            }
        }
    }

public:
    void I(int p) {
        if (n <= a.size()) {
            a.insert(a.begin() + n, p);
            sto.insert(sto.begin() + n, 0); 
            updateStoFrom(n);               
            n++;
        }
    }

    void D() {
        if (n > 0) {
            a.erase(a.begin() + n - 1);
            sto.erase(sto.begin() + n - 1);
            n--;
            updateStoFrom(n); 
        }
    }

    void L() {
        if (n > 0) n--;
    }

    void R() {
        if (n < a.size()) n++;
    }

    int Q(int k) {
        int ans = INT_MIN;
        for (int i = 0; i < k && i < sto.size(); i++) {
            ans = max(ans, sto[i]);
        }
        return ans;
    }
};

int main() {
    int a;
    a = read();
    editor in;
    vector<int> ans;
    for (int i = 0; i < a; i++) {
        char now;
        cin >> now;
        if (now == 'I') {
            int y = read();
            in.I(y);
        }
        if (now == 'D') {
            in.D();
        }
        if (now == 'L') {
            in.L();
        }
        if (now == 'R') {
            in.R();
        }
        if (now == 'Q') {
            int g = read();
            ans.push_back(in.Q(g));
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        write(ans[i]);
        cout << endl;
    }
    return 0;
}