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
class Node {
public:
    int data;
    Node *left, *right, *parent;
    Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
};
class Tree {
private:
    void depth(Node* root, int currd, int &maxd) {
        if (root == nullptr) {
            return;
        }
        maxd = max(maxd, currd);
        depth(root->left, currd + 1, maxd);
        depth(root->right, currd + 1, maxd);
    }
    void seeyou(Node* node) {
        if (node == nullptr) {
            return;
        }
        seeyou(node->left);
        seeyou(node->right);
        delete node;
    }
    void dfs(Node* node, int d) {
        if (node == nullptr) return;
        node->data = d;
        if (node->left) dfs(node->left, d + 1);
        if (node->right) dfs(node->right, d + 1);
    }
public:
    Node* root;
    vector<Node*> nodes;
    Tree(int n, const vector<pair<int, int>>& childs) {
        nodes.resize(n + 1, nullptr);
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node(0);
        }
        for (int i = 0; i != n - 1; i++) {
            int l = childs[i].first;
            int r = childs[i].second;
            if (!nodes[l]->left) {
                nodes[l]->left = nodes[r];
                nodes[r]->parent = nodes[l];
            } else {
                nodes[l]->right = nodes[r];
                nodes[r]->parent = nodes[l];
            }
        }
        root = nodes[1];
        dfs(nodes[1], 1);
    }
    void getdepth() {
        int macd = 0;
        depth(root, 1, macd);
        write(macd);
    }
    void getwidth() {
        if (!root) return;
        int maxWidth = 0;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            maxWidth = max(maxWidth, levelSize);
            for (int i = 0; i < levelSize; ++i) {
                Node* curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        write(maxWidth);
    }
    Node* findLCA(Node* u, Node* v) {
        while (u != v) {
            if (u->data > v->data) u = u->parent;
            else v = v->parent;
        }
        return u;
    }
    int getdistance(int x, int y) {
        Node* u = nodes[x];
        Node* v = nodes[y];
        Node* lca = findLCA(u, v);
        int dX = nodes[x]->data;
        int dY = nodes[y]->data;
        int dLCA = lca->data;
        return 2 * dX + dY - 3 * dLCA;
    }
    ~Tree() {
        seeyou(root);
    }
};
int main() {
    int n = read();
    vector<pair<int, int>> g;
    for (int i = 0; i != n - 1; i++) {
        int l = read();
        int r = read();
        g.push_back({l, r});
    }
    int x = read();
    int y = read();
    Tree sss(n, g);
    sss.getdepth();
    cout << endl;
    sss.getwidth();
    cout << endl;
    int ans = sss.getdistance(x, y);
    write(ans);
    return 0;
}
