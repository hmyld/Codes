#include<bits/stdc++.h>
using namespace std;
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
void write(int x) {
    if (x < 0) {
        x = -x;
        putchar('-');
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
struct Node {
    int data;
    int left, right;
    int parent;
    Node() : data(0), left(0), right(0), parent(0) {}
};
int bfs(vector<Node*>& tree, int start_node) {
    queue<pair<int, int>> q;
    vector<bool> visited(tree.size(), false);
    int ans = 0;
    q.push({start_node, 0});
    visited[start_node] = true;
    while (!q.empty()) {
        int current = q.front().first;
        int distance = q.front().second;
        q.pop();
        ans += tree[current]->data * distance;
        int left = tree[current]->left;
        if (left != 0 && !visited[left]) {
            q.push({left, distance + 1});
            visited[left] = true;
        }
        int right = tree[current]->right;
        if (right != 0 && !visited[right]) {
            q.push({right, distance + 1});
            visited[right] = true;
        }
        int parent = tree[current]->parent;
        if (parent != 0 && !visited[parent]) {
            q.push({parent, distance + 1});
            visited[parent] = true;
        }
    }
    return ans;
}
int main() {
    int n;
    n = read();
    vector<Node*> tree(n + 1);
    for (int i = 1; i <= n; i++) {
        tree[i] = new Node;
        tree[i]->data = read();
        tree[i]->left = read();
        tree[i]->right = read();
    }
    for (int i = 1; i <= n; i++) {
        int left = tree[i]->left;
        int right = tree[i]->right;

        if (left != 0) {
            tree[left]->parent = i;
        }
        if (right != 0) {
            tree[right]->parent = i;
        }
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n;i++){
        ans = min(bfs(tree, i), ans);
    }
    write(ans);
    for (int i = 1; i <= n; i++) {
        delete tree[i];
    }
    return 0;
}