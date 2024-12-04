#include <bits/stdc++.h>
using namespace std;
void y(int n, int k) {
    vector<int> circle;
    for (int i = 1; i <= n; ++i) {
        circle.push_back(i);
    }
    int index = 0;
    while (!circle.empty()) {
        index = (index + k - 1) % circle.size();
        cout << circle[index]<<" ";
        circle.erase(circle.begin() + index);
    }
}
int main() {
    int n, k;
    cin >> n >> k;
    y(n, k);
    return 0;
}
