#include <iostream>
#include <cmath>
using namespace std;
const int MOD = 9901;
long long pow_mod(long long a, long long b, long long p) {
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
long long factor_sum(long long a, long long b) {
    if (a == 0) return 0;
    if (b == 0) return 1;
    long long sum = 1;
    for (int p = 2; p * p <= a; ++p) {
        if (a % p == 0) {
            int count = 0;
            while (a % p == 0) {
                a /= p;
                count++;
            }
            long long factor_term = (pow_mod(p, b * count + 1, MOD) - 1 + MOD) % MOD;
            long long p_inverse = (p - 1 == 0) ? 1 : pow_mod(p - 1, MOD - 2, MOD);
            factor_term = (factor_term * p_inverse) % MOD;
            sum = (sum * factor_term) % MOD;
        }
    }
    if (a > 1) {
        long long factor_term = (pow_mod(a, b + 1, MOD) - 1 + MOD) % MOD;
        long long a_inverse = (a - 1 == 0) ? 1 : pow_mod(a - 1, MOD - 2, MOD);
        factor_term = (factor_term * a_inverse) % MOD;
        sum = (sum * factor_term) % MOD;
    }
    return (sum + MOD) % MOD;
}

bool is_prime(int n) {
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
    cin >> a >> b;
    if(is_prime(a)&&b==1){
        cout << pow_mod(a, b, MOD) + 1;
        return 0;
    }
    cout << factor_sum(a, b) << endl;
    return 0;
}