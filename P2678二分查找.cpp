#include<bits/stdc++.h>
using namespace std;
// 注释是AI加的
// 读取整数的函数
int read() {
    int x = 0, w = 1;
    char ch = 0;
    // 读取字符直到遇到数字
    while (ch < '0' || ch > '9') {  
        if (ch == '-') w = -1;        // 判断是否为负数
        ch = getchar();               // 继续读入
    }
    // 将读入的字符转换为数字
    while (ch >= '0' && ch <= '9') {  
        x = x * 10 + (ch - '0');  // 逐位构建数字
        ch = getchar();           // 继续读入
    }
    return x * w;  // 返回数字，考虑正负号
}

// 输出整数的函数
void write(int x) {
    if (x < 0) {  // 如果是负数
        x = -x;   // 取绝对值
        putchar('-');  // 输出负号
    }
    if (x > 9) write(x / 10);  // 递归输出高位数字
    putchar(x % 10 + '0');  // 输出末位数字
}

// 判断是否可以移除指定数量的点
bool remove(int b, int c, int a, int mid, const vector<int> &fuc) {
    if (b == 0) {  // 如果没有点
        return (a < mid) ? (1 <= c) : false;  // 根据条件返回
    }

    int kill = 0;  // 统计需要移除的点的数量
    int start = 0; // 当前段的起始位置

    // 判断第一个点是否需要移除
    if (fuc[0] - start < mid) {
        kill++;
    } else {
        start = fuc[0];  // 更新起始位置
    }

    // 遍历后续的点
    for (int i = 1; i != b; i++) {
        if (fuc[i] - start < mid) {  // 如果当前点与起始位置的距离小于 mid
            kill++;  // 需要移除
        } else {
            start = fuc[i];  // 更新起始位置
        }
    }

    // 判断最后一段
    if (a - start < mid) {
        kill++;  // 需要移除
    }

    // 如果移除的点数量小于等于 c，返回 true
    if (kill <= c) {
        return true;
    }
    return false;  // 否则返回 false
}

int main() {
    int a, b, c;
    a = read();  // 读取 a
    b = read();  // 读取 b
    c = read();  // 读取 c

    // 特殊情况处理
    if (a == 0 || b == 0) {
        write(a);  // 如果 a 或 b 为 0，输出 a
        return 0;  // 结束程序
    }

    vector<int> d(b);  // 创建存储点位置的向量
    for (int i = 0; i != b; i++) {
        d[i] = read();  // 读取 b 个点的位置
    }

    // 当 c 为 0 时
    if (c == 0) {
        int ans;  // 最小间隔
        for (int i = 0; i != b; i++) {
            if (i == 0) {
                ans = d[i];  // 第一个点的间隔
            } else {
                ans = min(ans, d[i] - d[i - 1]);  // 更新最小间隔
            }
        }
        ans = min(a - d[b - 1], ans);  // 处理最后一段的间隔
        write(ans);  // 输出结果
        return 0;  // 结束程序
    }

    // 二分查找的范围
    int low = 1;
    int high = a;
    int mid = (low + high) / 2;

    // 二分查找
    while (low <= high) {
        mid = (low + high) / 2;  // 计算中间值
        // 调用 remove 函数判断是否可以移除
        if (remove(b, c, a, mid, d)) {
            low = mid + 1;  // 可以移除，继续查找更大的 mid
        } else {
            high = mid - 1; // 不可以移除，查找更小的 mid
        }
    }

    write(high);  // 输出结果
}



