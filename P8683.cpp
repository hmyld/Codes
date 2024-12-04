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
signed main() {
    int n = read();
    int m = read();
    int total = n + m + 1;
    vector<int> nums(total);
    for (int i = 0; i < total; ++i) {
        nums[i] = read();
    }
    sort(nums.begin(), nums.end());
    int ans = 0;
    if (m == 0) {
        for (int i = 0; i < total; ++i) {
            ans += nums[i];
        }
    } else {
        ans = nums[total - 1] - nums[0];
        for (int i = 1; i < total - 1; ++i) {
            ans += abs(nums[i]);
        }
    }
    write(ans);
    return 0;
}


