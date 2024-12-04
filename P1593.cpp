#include <bits/stdc++.h>
using namespace std;
long long read() {
    long long x = 0, w = 1;
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
void write(long long x) {
    if (x < 0) {  
        x = -x;
        putchar('-');
    }
    if (x > 9) write(x / 10);  
    putchar(x % 10 + '0');   
}
const int q = 9901;
long long making(long long a, long long b, long long p) {
    long long ans = 1;
    long long temp = a % p;
    while (b > 0) {
        if (b & 1) {
            ans = (ans * temp) % p;
        }
        temp *= temp;
        temp %= p;
        b >>= 1;
    }
    return ans;
}
long long ddd(long long a, long long b) {
    if (a == 0) return 0;
    if (b == 0) return 1;
    long long sum = 1;
    for (int p = 2; p * p <= a; p++) {
        if (a % p == 0) {
            int g = 0;
            while (a % p == 0) {
                a /= p;
                g++;
            }
            long long sss = (making(p, b * g + 1, q) - 1 + q) % q;
            long long aaa = (p - 1 == 0) ? 1 : making(p - 1, q - 2, q);
            sss = (sss * aaa) % q;
            sum = (sum * sss) % q;
        }
    }
    if (a > 1) {
        long long sss = (making(a, b + 1, q) - 1 + q) % q;
        long long aaa = (a - 1 == 0) ? 1 : making(a - 1, q - 2, q);
        sss = (sss * aaa) % q;
        sum = (sum * sss) % q;
    }
    return (sum + q) % q;
}
bool fuckyou(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
int main() {
    long long a, b;
    a = read();
    b = read();
    if(fuckyou(a)&&b==1){
        cout << making(a, b, q) + 1;
        return 0;
    }
    write(ddd(a, b));
    return 0;
}