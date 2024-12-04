#include <bits/stdc++.h> //彪准头文件
using namespace std;
//这是一个进行一次每位与前一位异或操作的函数，就叫once，便于后续操作。
string once(string &input) {
    string temp = input;
    int n = input.size();
    for (int i = 1; i < n; ++i) {
        temp[i] = ((input[i - 1] - '0') ^ (input[i] - '0')) + '0';
    }
    return temp;
}
int main() {
    long long length, times;
    string input;
    cin >> length >> times >> input;//输入部分
    string inspect = input;//储存原始input字符串，以便后续操作检查循环节和重新开始异或操作
    long long cycle_length = 1; 
    input = once(input);//这里cycle_length记录循环节长度，然后进行一次操作。所以初始化长度是1。这样做可以优化掉哈希表检查以节省内存
    //这个循环用来找循环节
    for (long long i = 0; i < times - 1; i++) {
        if (inspect == input) {//这里是退出循环条件，就是检测到一个和原始字符串一样的字符串之后进行后续操作
            times %= cycle_length;//将循环次数对cycle_length取余数，和你高中数学学过的周期函数有异曲同工之妙
            break;//这个东西就是用来找循环节的，找到直接跑
        } else {
            cycle_length++;
            input = once(input);
        }
    }
    //通过刚才找到的次数对循环节取余数得到的数对原始字符串进行对应次数操作
    for (long long i = 0; i < times; i++) {
        inspect = once(inspect);
    }
    //以下是输出部分
    int n = inspect.size();
    for (long long i = 0; i < n; i++) {
        putchar(inspect[i]);
    }
    return 0;
}