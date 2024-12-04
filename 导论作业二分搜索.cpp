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
bool Binary_search(vector<int> &a, int target, int index_max, int index_min, int &ans) {
    if(index_max<index_min){
        return false;
    }
    int mid = (index_max + index_min) / 2;
    if(a[mid]==target){
        ans = mid;
        return true;
    }
    if(a[mid]>target){
        return Binary_search(a, target, mid, index_min, ans);
    }else{
        return Binary_search(a, target, index_max, mid + 1, ans);
    }
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
    int mac = inspect.size();
    if(Binary_search(inspect, r, mac, 0, ans)){
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