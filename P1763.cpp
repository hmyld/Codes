#include <bits/stdc++.h> 
#define int long long
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
const int max_depth = 11;
int max_num = 10000007;
int depth;
int max_a;
vector<int> temp(max_depth + 1, max_num + 1);
vector<int> ans(max_depth + 1, max_num + 1);
int a, b, c;
bool target_lock;
int whatisgcd(int x, int y) {
    if (y == 0) {
        return x;
    } else {
        return whatisgcd(y, x % y);
    }
}
void dfs(int a, int b, int x) {
    if (x > depth) return;
    if (a == 1) {
        temp[x] = b;
        if (!target_lock || temp[depth] < ans[depth]) {
            for (int i = 1; i <= depth; i++) {
                ans[i] = temp[i];
            }
        }
        target_lock = true;
        return;
    }
    if (x == depth - 1) {
        const int l = ((b << 2) / (a * a)) + 1;
        const int r = min(((max_a << 1)) / a, max_a * (max_a - 1) / b);
        for (int i = l; i <= r; i++) {
            int delta = a * a * i * i - ((b * i) << 2);
            int Sqrt = sqrt(delta);
            if (Sqrt * Sqrt != delta || ((a * i - Sqrt) & 1)) {
				continue;
			}
            temp[x] = (a * i - Sqrt) >> 1;
            temp[x + 1] = (a * i + Sqrt) >> 1;
            if (!target_lock || temp[depth] < ans[depth]) {
                for (int j = 1; j <= depth; j++) {
                    ans[j] = temp[j];
                }
                target_lock = true;
            }
        }
        return;
    }
    int l = max((b + a - 1) / a, temp[x - 1] + 1);
    int r = min((((depth - x + 1) * b + a - 1) / a), max_a);
    if (target_lock && r >= ans[depth]) {
        r = ans[depth] - 1;
    }
    for (int i = l; i <= r; i++) {
        temp[x] = i;
        int A = a * i - b, B = b * i;
        int n = whatisgcd(A, B);
        dfs(A / n, B / n, x + 1);
    }
}
signed main() {
    a = read();
    b = read();
    c = whatisgcd(a, b);
    a /= c;
    b /= c;
    temp[0] = 1;
    for (depth = 1; depth <= max_depth - 1; depth++) {
        ans[depth] = temp[depth] = max_num + 1;
        for (max_a = 100000; max_a <= max_num; max_a *= 10) {
            dfs(a, b, 1);
            if (target_lock) {
                for (int i = 1; i <= depth; i++) {
                    write(ans[i]);
                    cout << ' ';
                }
                cout << endl;
                return 0;
            }
        }
    }
    return 0;
}










































// B C BD B D D