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

// 计算前缀和
void pro(vector<vector<int>>& arr, vector<vector<int>>& arrs, int sizem, int sizen) {
    arrs[0][0] = arr[0][0];
    for (int i = 1; i < sizem; i++) {
        arrs[i][0] = arr[i][0] + arrs[i-1][0];
    }
    for (int i = 1; i < sizen; i++) {
        arrs[0][i] = arr[0][i] + arrs[0][i-1];
    }
    for (int i = 1; i < sizem; i++) {
        for (int j = 1; j < sizen; j++) {
            arrs[i][j] = arr[i][j] + arrs[i-1][j] + arrs[i][j-1] - arrs[i-1][j-1];
        }
    }
}

int get_sum(const vector<vector<int>>& arrs, int i, int j, int a) {
    int total = arrs[i+a][j+a];
    if (i > 0) total -= arrs[i-1][j+a];
    if (j > 0) total -= arrs[i+a][j-1];
    if (i > 0 && j > 0) total += arrs[i-1][j-1];
    return total;
}

int main() {
    int sizem, sizen;
    cin >> sizem >> sizen;
    
    // 动态数组
    vector<vector<int>> arr(sizem, vector<int>(sizen, 0));
    vector<vector<int>> arrs(sizem, vector<int>(sizen, 0));

    for (int i = 0; i < sizem; i++) {
        for (int j = 0; j < sizen; j++) {
            arr[i][j] = read();
        }
    }

    // 计算前缀和
    pro(arr, arrs, sizem, sizen);

    int ans = 0;
    
    // 查找符合条件的子矩阵
    for (int i = 0; i < sizem; i++) {
        for (int j = 0; j < sizen; j++) {
            for (int a = 0; a + i < sizem && a + j < sizen; a++) {
                int sum = get_sum(arrs, i, j, a);
                if (sum == (a + 1) * (a + 1)) {  // 确认子矩阵和是否符合条件
                    ans = max(ans, a + 1);  // 更新最大子矩阵边长
                }
            }
        }
    }

    write(ans);
    return 0;
}
