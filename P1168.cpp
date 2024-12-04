#include <bits/stdc++.h>
using namespace std;
const int p = 9901;
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
int main(){
    int a;
    a = read();
    vector<int> qq;
    int tgt;
    for (int i = 0; i != a;i++){
        tgt = read();
        qq.insert(upper_bound(qq.begin(), qq.end(), tgt), tgt);
        if(i%2==0){
            write(qq[i / 2]);
            cout << endl;
        }
    }
    return 0;
}