// STL
#include <bits/stdc++.h>
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
void coutarr(vector <int>& arr) {
    /*for (int i = 0; i < arr.size(); i++) {
        write (arr[i]);
        cout << " ";
    }*/
    for(auto i: arr) write(i),cout << " ";
    cout << endl;
}
// 插入排序逻辑
vector<int> selection_sort(vector<int>&target){
    vector<int> ans;
    while(target.size()){
        int r = 0;
        int contrast = target[0];
        for (int i = 1; i != target.size();i++) {
            if(target[i]<contrast){
                r = i;
                contrast = target[i];
            }
        }
        ans.push_back(contrast);
        target.erase(target.begin() + r);
    }
    return ans;
}
int main(){
    int a;// 先输入数组长度，方便后续处理
    a = read();
    vector <int> b (a);
    for (int i = 0; i != a; i++){
        b[i] = read ();
    }
    b = selection_sort(b);
    coutarr(b);
    return 0;
}