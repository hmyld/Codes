#include<bits/stdc++.h>
using namespace std;
int read () {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {  // ch 不是数字时
        if (ch == '-') w = -1;        // 判断是否为负
        ch = getchar ();               // 继续读入
    }
    while (ch >= '0' && ch <= '9') {  // ch 是数字时，我们输入结束标志为空格或回车。
        x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面

    ch = getchar ();  // 继续读入
    }
    return x * w;  // 数字 * 正负号 = 实际数值
}

void write (int x) {
    if (x < 0) {  // 判负 + 输出负号 + 变原数为正数
        x = -x;
        putchar ('-');
    }
    if (x > 9) write (x / 10);  // 递归，将除最后一位外的其他部分放到递归中输出
    putchar (x % 10 + '0');  // 已经输出（递归）完 x 末位前的所有数字，输出末位
}
int main(){
    int a;
    a = read();
    priority_queue<int, vector<int>, std::greater<int>> pq;
    for(int i = 0; i != a; i++){
        int x = read ();
        pq.push(x);
    }

    int ans = 0;

    while(pq.size() > 1){
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        int merged = (int)first + second;
        ans += merged;
        pq.push(merged);
    }

    write(ans);
    return 0;
}