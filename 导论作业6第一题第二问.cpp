#include <bits/stdc++.h>
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
int main() {
    queue<char> a;
    a.push('A');
    a.push('B');
    a.push('C');
    putchar(a.front());
    a.pop();
    a.push('D');
    a.push('E');
    vector<char> b;
    while(!a.empty()){
        b.push_back(a.front());
        a.pop();
    }
    for (int i = 0; i != b.size(); i++) {
        putchar(b[i]);
    }
    putchar(b[0]);
    return 0;
}