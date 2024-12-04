#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[1001] = {};
    int b, a[1001] = {}, c[1001] = {}, d;
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
    for (int i = 0; i != d; i++) {
        cout << c[i];
    }
    return 0;
}

