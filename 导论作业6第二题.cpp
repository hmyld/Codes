#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    char data;
    Node *left;
    Node *right;
    Node(char a) : data(a), left(nullptr), right(nullptr) {}
};
void print_linked_graph(Node *node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    if (!node->left) {
        cout << "nullptr ";
    } else {
        cout << node->left->data << " ";
    }
    if (!node->right) {
        cout << "nullptr ";
    } else {
        cout << node->right->data << " ";
    }
    cout << endl;
    print_linked_graph(node->left);
    print_linked_graph(node->right);
}
int main() {
    Node *root = new Node('A');
    Node *B = new Node('B');
    Node *C = new Node('C');
    Node *D = new Node('D');
    Node *E = new Node('E');
    Node *F = new Node('F');
    root->left = B;
    root->right = C;
    B->left = D;
    B->right = E;
    C->right = F;
    print_linked_graph(root);
    return 0;
}
