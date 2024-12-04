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
    Node (int val) : data(val), left(nullptr), right(nullptr) {};
};
int c[105];
void depth(Node* root,int currd,int &maxd) {
    if (root == nullptr){
        return;
    }
    c[currd]++;
    if(currd > maxd){
        maxd = currd;
    }
    depth(root->left, currd + 1, maxd);
    depth(root->right, currd + 1, maxd);
}
void seeyou(Node* node){
    if(node == nullptr){
        return;
    }
    seeyou(node->left);
    seeyou(node->right);
    delete(node);
}
class Tree{
    public:
    Node* root;
    //树的结构
    Tree(int n, const vector<pair<int, int>>& childs){
        vector<Node*> nodes(n + 1, nullptr);
        for(int i = 1; i <= n; ++i){
            nodes[i] = new Node(i);
        }
        //左右子节点
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
        //根节点1
        root = nodes[1];
    }
    void getdepth(){
        int macd = 0;
        depth(root, 1, macd);
        write(macd);
    }
    
    ~Tree(){
        seeyou(root);
    }
};
int main(){
    int n = read();
    vector<pair<int, int>> g(n + 1, {0, 0});
    for(int i = 1; i < n; i++){
        int l = read();
        int r = read();
        g[i] = {l, r};
    }
    Tree sss(n, g);
    sss.getdepth();
    cout << endl;
    int mx = 0;
    for (int i = 1; i <= 100;++i)
    {
        mx = max(mx, c[i]);
    }
    write(mx);
    return 0;
}
// 下面有注释版本



/*#include<bits/stdc++.h>
using namespace std;

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

// 节点类，表示树的每个节点
class Node {
public:
    int data;          // 节点的数据
    Node* left;       // 左子节点
    Node* right;      // 右子节点
    Node(int val) : data(val), left(nullptr), right(nullptr) {};  // 构造函数
};

// 深度数组，记录每层的节点数量
int c[105];

// 递归计算树的深度
void depth(Node* root, int currd, int &maxd) {
    if (root == nullptr) {  // 如果节点为空，返回
        return;
    }
    c[currd]++;  // 当前层的节点数量加1
    if (currd > maxd) {  // 更新最大深度
        maxd = currd;
    }
    // 递归遍历左右子树
    depth(root->left, currd + 1, maxd);
    depth(root->right, currd + 1, maxd);
}

// 递归释放树的节点内存
void seeyou(Node* node) {
    if (node == nullptr) {  // 如果节点为空，返回
        return;
    }
    // 先释放左右子树
    seeyou(node->left);
    seeyou(node->right);
    delete(node);  // 释放当前节点的内存
}

// 树类，管理树的结构和操作
class Tree {
public:
    Node* root;  // 树的根节点

    // 构造函数，根据输入的节点信息构建树
    Tree(int n, const vector<pair<int, int>>& childs) {
        vector<Node*> nodes(n + 1, nullptr);  // 创建节点指针数组
        for (int i = 1; i <= n; ++i) {
            nodes[i] = new Node(i);  // 创建每个节点
        }
        // 根据输入的子节点信息设置左右子节点
        for (int i = 1; i <= n; ++i) {
            int l = childs[i].first;   // 左子节点
            int r = childs[i].second;  // 右子节点
            if (l != 0) {
                nodes[i]->left = nodes[l];  // 设置左子节点
            }
            if (r != 0) {
                nodes[i]->right = nodes[r];  // 设置右子节点
            }
        }
        // 根节点为 1
        root = nodes[1];
    }

    // 获取树的深度并输出
    void getdepth() {
        int macd = 0;  // 最大深度
        depth(root, 1, macd);  // 计算深度
        write(macd);  // 输出最大深度
    }

    // 析构函数，释放树的内存
    ~Tree() {
        seeyou(root);  // 调用释放函数
    }
};

int main() {
    int n = read();  // 读取节点数
    vector<pair<int, int>> g(n + 1, {0, 0});  // 创建子节点信息数组
    for (int i = 1; i < n; i++) {
        int l = read();  // 读取左子节点
        int r = read();  // 读取右子节点
        g[i] = {l, r};   // 存储子节点信息
    }
    Tree sss(n, g);  // 创建树对象
    sss.getdepth();  // 获取并输出树的深度
    cout << endl;    // 换行
    int mx = 0;      // 最大层的节点数量
    for (int i = 1; i <= 100; ++i) {
        mx = max(mx, c[i]);  // 更新最大节点数量
    }
    write(mx);  // 输出最大节点数量
    return 0;   // 结束程序
}
*/ 