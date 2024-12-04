// 如果不能使用STL，希望您能告知我
#include<bits/stdc++.h>
using namespace std;
// 快读
int read () {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;    
        ch = getchar ();          
    }
    while (ch >= '0' && ch <= '9') { 
        x = x * 10 + (ch - '0');

    ch = getchar ();
    }
    return x * w;
}
// 快写
void write (int x) {
    if (x < 0) {
        x = -x;
        putchar ('-');
    }
    if (x > 9) write (x / 10); 
    putchar (x % 10 + '0');  
}
// 这个函数用来输出vector数组
void coutarr(vector <int>& arr) {
    /*for (int i = 0; i < arr.size(); i++) {
        write (arr[i]);
        cout << " ";
    }*/
    for(auto i: arr) write(i),cout << " ";
    cout << endl;
}
// 合并数组的逻辑
void merge(vector <int>& arr, int l , int m , int r){
    int lsize , rsize;
    lsize = m - l + 1;
    rsize = r - m;
    vector <int> ltemp (lsize);
    vector <int> rtemp (rsize);
    for(int i = 0; i != lsize; i++){
        ltemp[i] = arr[l + i];
    }
    for(int i = 0; i != rsize; i++){
        rtemp[i] = arr[m + 1 + i];
    }
    int a = 0; int b = 0; int pos = l;
    while (a < lsize && b < rsize) {
        if (ltemp[a] <= rtemp[b]) {
            arr[pos] = ltemp[a];
            a++; 
        } else {
            arr[pos] = rtemp[b];
            b++;
        }
        pos++;
    }
    if (a < lsize){
        while(1){
            arr[pos] = ltemp[a];
            a++;
            pos++;
            if (a == lsize) break;
        }
    }else if (b < rsize){
        while(1){
            arr[pos] = rtemp[b];
            b++;
            pos++;
            if (b == rsize) break;
        }
    }
}
// 递归逻辑
void dg(vector <int>& arr, int l, int r){
    if(l >= r){
        return;
    }
    int m = (l + r) / 2;
    dg (arr, l, m);
    dg (arr, m + 1, r);
    merge (arr, l, m, r);
}

int main(){
    int a;// 先输入数组长度，方便后续处理
    a = read();
    vector <int> b (a);
    for (int i = 0; i != a; i++){
        b[i] = read ();
    }
    dg (b, 0, b.size () - 1);
    coutarr (b);
    return 0;
}