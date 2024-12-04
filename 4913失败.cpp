#include <bits/stdc++.h>
using namespace std;

// 快速读入函数
inline int read() {
    int x = 0, w = 1;
    char ch = getchar();
    while (!isdigit(ch) && ch != '-' && ch != EOF) ch = getchar();
    if (ch == '-') { w = -1; ch = getchar(); }
    while (isdigit(ch)) { x = x * 10 + (ch - '0'); ch = getchar(); }
    return x * w;
}

// 快速写出函数
void write(int x) {
    if (x == 0) { putchar('0'); return; }
    if (x < 0) { putchar('-'); x = -x; }
    char s[12];
    int idx = 0;
    while (x > 0) { s[idx++] = '0' + (x % 10); x /= 10; }
    while (idx--) putchar(s[idx]);
}

// 定义树的节点
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 定义树的结构
class Tree {
public:
    Node* root;

    // 构造函数，根据子节点信息构建树
    Tree(int n, const vector<pair<int, int>>& childs) {
        // 创建所有节点
        vector<Node*> nodes(n + 1, nullptr);
        for(int i = 1; i <= n; ++i){
            nodes[i] = new Node(i);
        }

        // 链接左右子节点
        for(int i = 1; i <= n; ++i){
            int l = childs[i].first;
            int r = childs[i].second;
            if(l != 0){
                nodes[i]->left = nodes[l];
            }
            if(r != 0){
                nodes[i]->right = nodes[r];
            }
        }

        // 根节点为1
        root = nodes[1];
    }

    // 使用广度优先搜索计算树的深度
    int getDepth() {
        if(root == nullptr) return 0;
        queue<Node*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            int size = q.size();
            depth++;
            for(int i = 0; i < size; ++i){
                Node* node = q.front(); q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return depth;
    }

    // 析构函数，释放内存
    ~Tree(){
        // 使用后序遍历释放所有节点
        if(root == nullptr) return;
        stack<Node*> s;
        Node* prev = nullptr;
        s.push(root);
        while(!s.empty()){
            Node* curr = s.top();
            if((curr->left == nullptr && curr->right == nullptr) ||
               (prev != nullptr && (prev == curr->left || prev == curr->right))){
                s.pop();
                delete curr;
                prev = curr;
            }
            else{
                if(curr->right) s.push(curr->right);
                if(curr->left) s.push(curr->left);
            }
        }
    }
};

int main(){
    int n = read();
    // 使用1-based索引，0号节点不使用
    vector<pair<int, int>> g(n + 1, {0, 0});
    for(int i = 1; i <= n; i++){
        int l = read();
        int r = read();
        g[i] = {l, r};
    }

    // 构建树
    Tree sss(n, g);

    // 计算深度
    int ans = sss.getDepth();

    // 输出结果
    write(ans);
    return 0;
}
