#include<bits/stdc++.h>
using namespace std;
int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {  // ch 不是数字时
        if (ch == '-') w = -1;        // 判断是否为负
        ch = getchar();               // 继续读入
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
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};
class BinarySearchTree{
    Node* root;
    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            // 如果当前节点为空，创建一个新节点并返回
            return new Node(key);
        }

        if (key < node->data) {
            // 如果key小于当前节点的数据，递归插入到左子树
            node->left = insert(node->left, key);
        }
        else if (key > node->data) {
            // 如果key大于当前节点的数据，递归插入到右子树
            node->right = insert(node->right, key);
        }
        // 如果key等于当前节点的数据，不插入重复值
        return node;
    }
    public:
    // 构造函数：初始化根节点为nullptr
    BinarySearchTree() : root(nullptr) {}

    // 插入函数：对外提供的接口，调用私有的递归插入函数
    void insert(int key) {
        root = insert(root, key);
    }
};
int main(){
    int a=read(),b=read();
    int c=a+b;
    write(c);
    return 0;
}