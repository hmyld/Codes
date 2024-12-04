#include <bits/stdc++.h>
using namespace std;
int main() {
    unsigned long long s;
    cin >> s;
    if (s < 4) {
        cout << 0 << endl;
        return 0;
    }
    unsigned long long ans;
    ans = s * (s - 1) / 2 * (s - 2) / 3 * (s - 3) / 4;
    cout << ans << endl;
    return 0;
}
