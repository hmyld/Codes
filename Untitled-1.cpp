#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    int tgt[200005];
    unordered_map<int, int> countMap;

    // 读入数据并统计每个元素出现的次数
    for (int i = 0; i < n; i++) {
        cin >> tgt[i];
        countMap[tgt[i]]++;
    }

    int ans = 0;
    // 计算满足条件的对
    for (int i = 0; i < n; i++) {
        int target = tgt[i] - c; // 计算目标 B
        if (countMap.find(target) != countMap.end()) {
            ans += countMap[target]; // 加上对应的 B 的出现次数
            // 如果 tgt[i] == target，说明这是同一个数，我们需要减去1
            if (target == tgt[i]) {
                ans--;
            }
        }
    }

    cout << ans << endl; // 输出结果
    return 0;
}
