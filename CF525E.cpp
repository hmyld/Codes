#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

// 计算所有子集和，返回一个哈希表，键是子集和，值是出现的次数
unordered_map<long long, int> compute_subset_sums(const vector<int>& arr, int k) {
    unordered_map<long long, int> subset_sums;
    int size = arr.size();
    for (int mask = 0; mask < (1 << size); ++mask) {
        long long sum_without_fact = 0;
        long long sum_with_fact = 0;
        int count_fact = 0;
        for (int i = 0; i < size; ++i) {
            if (mask & (1 << i)) {  // 当前子集包含 arr[i]
                sum_without_fact += arr[i];
                sum_with_fact += tgamma(arr[i] + 1);  // 计算阶乘 arr[i]!
                count_fact++;
            }
        }
        if (count_fact <= k) {  // 只考虑使用了不超过 k 个阶乘符号的子集
            subset_sums[sum_without_fact]++;
            if (count_fact > 0) {
                subset_sums[sum_with_fact]++;
            }
        }
    }
    return subset_sums;
}

int meet_in_the_middle(int n, int k, long long S, const vector<int>& a) {
    // 将数组 a 分成两部分
    int mid = n / 2;
    vector<int> left_part(a.begin(), a.begin() + mid);
    vector<int> right_part(a.begin() + mid, a.end());

    // 计算左半部分和右半部分的所有子集和
    auto left_sums = compute_subset_sums(left_part, k);
    auto right_sums = compute_subset_sums(right_part, k);

    // 查找符合条件的配对
    int result = 0;
    for (auto& left : left_sums) {
        long long target_sum = S - left.first;
        if (right_sums.find(target_sum) != right_sums.end()) {
            result += left.second * right_sums[target_sum];
        }
    }

    return result;
}

int main() {
    int n, k;
    long long S;
    cin >> n >> k >> S;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 调用算法并输出结果
    cout << meet_in_the_middle(n, k, S, a) << endl;

    return 0;
}
