// 如果不能使用STL，希望您能告知我
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
// 这个函数用来快速读入int
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
// 这个函数用来快速输出int
void write(int x) {
    if (x < 0) { 
        x = -x;  
        putchar('-'); 
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
int ans=-1;
// 这个函数用来实现线性搜索
bool Linear_search(vector<int> &a, int target, int &ans) {
    for (int i = 0; i != a.size();i++) {
        if(a[i]==target) {
            ans = i;
            return true;
        }
    }
    return false;
}
int main(){
    SetConsoleOutputCP(CP_UTF8);
    int n, r;
    n = read();//先输入数组长度以便于后续操作
    r = read();
    vector<int> inspect(n);
    for (int i = 0; i != n;i++) {
        inspect[i] = read();
    }
    if(Linear_search(inspect, r, ans)){
        cout << "发现数字";
        write(r);
        cout << "在0索引第";
        write(ans);
        cout << "位" << endl;
        return 0;
    }
    cout << "没找到" << endl;
    return 0;
}