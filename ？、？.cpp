#include <bits/stdc++.h>
using namespace std;
#define int long long
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
pair<int, int> windows(int N, int M, const vector<int>& teachers) {
    unordered_map<int, int> mark;
    int aaa = 0;
    int min_length = N;
    pair<int, int> ans = {1, N};
    int l = 0;
    for (int r = 0; r != N; r++) {
        if (mark.find(teachers[r]) == mark.end()) {
            aaa++;
        }
        mark[teachers[r]]++;
        while (aaa == M) {
            if (r - l < min_length) {
                min_length = r - l;
                ans = {l + 1, r + 1};
            }
            mark[teachers[l]]--;
            if (mark[teachers[l]] == 0) {
                aaa--;
            }
            l++;
        }
    }
    return ans;
}
signed main() {
    int N, M;
    N = read();
    M = read();
    vector<int> teachers(N);
    for (int i = 0; i < N; ++i) {
        teachers[i] = read();
    }
    pair<int, int> ans = windows(N, M, teachers);
    write(ans.first);
    putchar(' ');
    write(ans.second);
    return 0;
}
