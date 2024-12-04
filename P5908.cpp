#include <bits/stdc++.h>
using namespace std;

int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {  // ch 不是数字时
        if (ch == '-') w = -1;  // 判断是否为负
        ch = getchar();  // 继续读入
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

unordered_map<int, vector<int>> adjoint;
unordered_map<int, bool> visited;

void join(int u, int v) {
    adjoint[u].push_back(v);  // 添加边 u -> v
    adjoint[v].push_back(u);  // 如果是无向图，添加边 v -> u
}

int main() {
    int n = read();  // 节点数
    int b = read();  // 层数

    // 读取图的边
    for (int i = 0; i < n - 1; i++) {
        int u = read();
        int v = read();
        join(u, v);
    }

    queue<int> temp;
    int ans = 0;
    temp.push(1);  // 从节点1开始
    visited[1] = true;

    // 层次遍历
    while (!temp.empty() && b > 0) {
        int levelSize = temp.size();  // 当前层的节点数
        vector<int> store;  // 存储当前层的所有邻接节点

        // 遍历当前层的所有节点
        while (levelSize--) {
            int d = temp.front();
            temp.pop();

            // 遍历节点的邻接节点
            for (int i = 0; i < adjoint[d].size(); i++) {
                int neighbor = adjoint[d][i];
                if (!visited[neighbor]) {  // 如果未访问过
                    visited[neighbor] = true;  // 标记为已访问
                    store.push_back(neighbor);  // 加入下一层
                }
            }
        }

        ans += store.size();  // 本层所有节点的数量即为本层要统计的数
        for (int i = 0; i < store.size(); i++) {
            temp.push(store[i]);  // 将下一层的节点加入队列
        }

        b--;  // 处理完一层，减少层数
    }

    write(ans);  // 输出答案
    return 0;
}
