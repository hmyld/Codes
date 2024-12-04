#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(int n, vector<vector<int>>& adj) {
    vector<int> in_degree(n, 0); // 入度数组
    vector<int> result;         // 存储拓扑排序结果

    // 计算每个顶点的入度
    for (int i = 0; i < n; i++) {
        for (int v : adj[i]) {
            in_degree[v]++;
        }
    }
// asdfjklasdfjklasdfjklasdfjklasdfjklasdfjklasdfjklasdfjklasdfjklasdfjklasdfjklasdfjklasdfjklasdfjklasdfjklasdfjklasdfjklasdfjklasdfjklasdfjklasdfjklasdfjkl
    // 将所有入度为 0 的节点加入队列
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    // 拓扑排序
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u); // 加入拓扑排序结果

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    // 检查是否成功排序
    if (result.size() != n) {
        throw runtime_error("Graph has a cycle!"); // 图中有环
    }

    return result;
}

int main() {
    int n = 6; // 节点数
    vector<vector<int>> adj = {
        {1, 2},    // 0 -> 1, 0 -> 2
        {3},       // 1 -> 3
        {3, 4},    // 2 -> 3, 2 -> 4
        {},        // 3
        {5},       // 4 -> 5
        {}         // 5
    };

    vector<int> result = topologicalSort(n, adj);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
