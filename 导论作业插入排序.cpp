// STL
#include <bits/stdc++.h>
using namespace std;

// 快读
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

// 快写
void write(int x) {
    if (x < 0) {
        x = -x;
        putchar('-');
    }
    if (x > 9) write(x / 10); 
    putchar(x % 10 + '0');  
}

void coutarr(vector<int>& arr) {
    for (auto i : arr) write(i), cout << " ";
    cout << endl;
}

// 插入排序逻辑
vector<int> insertion_sort(vector<int>& target) {
    int n = target.size();
    for (int i = 1; i < n; i++) {
        int key = target[i];
        int j = i - 1;
        while (j >= 0 && target[j] > key) {
            target[j + 1] = target[j];
            j--;
        }
        target[j + 1] = key;
    }
    return target;
}

int main() {
    int a; // 老规矩
    a = read();
    vector<int> b(a);
    for (int i = 0; i != a; i++) {
        b[i] = read();
    }
    b = insertion_sort(b);
    coutarr(b);
    return 0;
}
