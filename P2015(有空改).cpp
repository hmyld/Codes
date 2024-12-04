#include <bits/stdc++.h>
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
    int data_left;
    int data_right;
    Node* left;
    Node* right;
    Node* parent;
    Node(): data_left(0), data_right(0), left(nullptr), right(nullptr), parent(nullptr) {}
};
class bt {
private:
    vector<Node*> nodes;
public:
    Node* root=nullptr;
    bt(vector<pair<int, int>>& a, vector<int>& value, int r) {
        for (int i = 1; i <= r; i++) {
            Node* node = new Node();
            nodes.push_back(node);
        }
        if (!this->root) {
            this->root = nodes[a[0].first - 1];
        }
        for (int i = 0; i != a.size(); i++) {
            if (!nodes[a[i].first - 1]->parent && i != 0) {
                nodes[a[i].first - 1]->parent = nodes[a[i].second - 1];
                if (!nodes[a[i].second - 1]->left) {
                    nodes[a[i].second - 1]->left = nodes[a[i].first - 1];
                    nodes[a[i].second - 1]->data_left = value[i];
                }
                if (!nodes[a[i].second - 1]->right) {
                    nodes[a[i].second - 1]->right = nodes[a[i].first - 1];
                    nodes[a[i].second - 1]->data_right = value[i];
                }
                continue;
            }
            if (!nodes[a[i].first - 1]->left) {
                nodes[a[i].first - 1]->left = nodes[a[i].second - 1];
                nodes[a[i].first - 1]->data_left = value[i];
                continue;
            }
            if (!nodes[a[i].first - 1]->right) {
                nodes[a[i].first - 1]->right = nodes[a[i].second - 1];
                nodes[a[i].first - 1]->data_right = value[i];
                continue;
            }
        }
    }
    void seeyou(Node* root) {
        if (root == nullptr) {
            return;
        }
        seeyou(root->left);
        seeyou(root->right);
        delete root;
    }
    int find_one(Node* root) {
        if (!root) return INT_MAX;
        if (!root->left && !root->right) {
            if (root->parent) {
                return min(root->parent->data_left, root->parent->data_right);
            }
            return INT_MAX;
        }
        int left_min = find_one(root->left);
        int right_min = find_one(root->right);
        return min(left_min, right_min);
    }
    void pop_out(Node*& root, int min_weight) {
        if (!root) return;
        if (root->left && !root->left->left && !root->left->right) {
            if (root->left == root->parent->left && root->parent->data_left == min_weight) {
                delete root->left;
                root->left = nullptr;
                return;
            }
        }
        if (root->right && !root->right->left && !root->right->right) {
            if (root->right == root->parent->right && root->parent->data_right == min_weight) {
                delete root->right;
                root->right = nullptr;
                return;
            }
        }
        if (root->left) pop_out(root->left, min_weight);
        if (root->right) pop_out(root->right, min_weight);
    }
    ~bt() {
        seeyou(root);
    }
};
int main() {
    int N = read();
    int Q = read();
    vector<pair<int, int>> edges(N - 1);
    vector<int> value(N - 1);
    for (int i = 0; i != N - 1; i++) {
        edges[i].first = read();
        edges[i].second = read();
        value[i] = read();
    }
    bt tree(edges, value, N);
    int max_apples = 0;
    for (int i = 0; i != N - 1; i++) {
        max_apples += value[i];
    }
    write(max_apples);
    for (int i = 0; i != Q; i++) {
        int temp = tree.find_one(tree.root);
        cout << temp << endl;
        max_apples -= temp;
        tree.pop_out(tree.root, temp);
    }
    write(max_apples);
    return 0;
}
