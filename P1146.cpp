#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin >> a;
    cout << a;
    putchar('\n');
    for (int i = 0; i != a;i++){
        if(i%2==0){
            for (int j = 0; j <= i;j++){
                putchar('0');
            }
            for (int j = i + 1; j != a;j++){
                putchar('1');
            }
            putchar('\n');
        }else{
            for (int j = 0; j <= i;j++){
                putchar('1');
            }
            for (int j = i + 1; j != a;j++){
                putchar('0');
            }
            putchar('\n');
        }
    }
    return 0;
}