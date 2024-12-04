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
void dfs(const string& a, int index, const unordered_map<char, vector<char>>& rules, set<string>& ans) {
    if (index == a.size()) {
        ans.insert(a);
        return;
    }
    
    // 不变换当前数字
    dfs(a, index + 1, rules, ans);
    
    // 变换当前数字
    if (rules.count(a[index])) {
        for (char replacement : rules.at(a[index])) {
            string temp = a;
            temp[index] = replacement;
            dfs(temp, index + 1, rules, ans);
        }
    }
}

int main() {
    string a;
    int k;
    cin >> a >> k;

    unordered_map<char, vector<char>> rules; // 存储每个数字的变换规则
    for (int i = 0; i < k; i++) {
        int x = read();
        int y = read();
        rules[char(x + '0')].push_back(char(y + '0')); // 将 int 转换为 char，并存储到 vector
    }
    
    set<string> ans;
    dfs(a, 0, rules, ans);
    write(ans.size());
    return 0;
}