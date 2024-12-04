#include<bits/stdc++.h>
using namespace std;
int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {  // ch 不是数字时
        if (ch == '-') w = -1;        // 判断是否为负
        ch = getchar();               // 继续读入
    }
    while (ch >= '0' && ch <= '9') {  // ch 是数字时，我们输入结束标志为空格或回车。
        x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面

    ch = getchar();  // 继续读入
    }
    return x * w;  // 数字 * 正负号 = 实际数值
}
void write(int x) {
    if (x < 0) {  // 判负 + 输出负号 + 变原数为正数
        x = -x;
        putchar('-');
    }
    if (x > 9) write(x / 10);  // 递归，将除最后一位外的其他部分放到递归中输出
    putchar(x % 10 + '0');  // 已经输出（递归）完 x 末位前的所有数字，输出末位
}
int bfind(vector<int>&inst,int target){
    if (inst.size()==0){
        return 1;
    }
    int high = inst.size() - 1;
    int minm = 0;
    while(minm <= high){
        int middle = (high + minm) / 2;
        if (inst[middle] < target) {
            high = middle - 1;
        } else {
            minm = middle + 1;
        }
    }
    return minm;
}
int bfindh(vector<int>&inst,int target){
    if (inst.size()==0){
        return 1;
    }
    int high = inst.size() - 1;
    int minm = 0;
    while(minm<=high){
        int middle = (high + minm) / 2;
        if (inst[middle] >= target) {
            high = middle - 1;
        } else {
            minm = middle + 1;
        }
    }
    return minm;
}
int main(){
    int num;


    vector<int> b;
    vector<int> inst;
    vector<int> instt;
    while (scanf("%d", &num) != EOF) {
        b.push_back(num); 
    }
    int pos;
    for (int i = 0; i != b.size();i++){
        pos = bfind(inst, b[i]);
        if (pos < inst.size()) {
            inst[pos] = b[i];
        } else {
            inst.push_back(b[i]);
        }
    }
    write(inst.size());
    cout << endl;
    int poss;
    for (int i = 0; i != b.size();i++){
        poss = bfindh(inst, b[i]);
        if (poss < instt.size()) {
            instt[poss] = b[i];
        } else {
            instt.push_back(b[i]);
        }
    }
    write(instt.size());
    return 0;
}
