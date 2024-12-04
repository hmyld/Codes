#include <stdio.h>
#include <windows.h>
int main() {
    SetConsoleOutputCP(CP_UTF8);
    int t, a, b, c, d;
    scanf("%d", &t);
    if (t < 100 || t > 999) {
        printf("输入的数不是一个三位正整数。\n");
        return 1;
    }
    a = t % 10;       
    b = (t / 10) % 10;
    c = t / 100;      
    d = a * a * a + b * b * b + c * c * c;
    if (t == d)
        printf("%d是水仙花数！\n", t);
    else
        printf("%d不是水仙花数！\n", t);
    return 0;
}