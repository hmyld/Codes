#include <iostream>
using namespace std;
bool i(int year) {
    if (year % 400 == 0) {
        return true;
    } else if (year % 100 == 0) {
        return false;
    } else if (year % 4 == 0) {
        return true;
    } else {
        return false;
    }
}
int main() {
    int y, m;
    cin >> y >> m;
    int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (i(y) && m == 2) {
        cout << 29 << endl;
    } else {
        cout << d[m - 1] << endl;
    }
    return 0;
}
