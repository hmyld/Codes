#include<bits/stdc++.h>
using namespace std;
int fuck(int i){
    int count=0;
    for (int j=1;j<=i;j++){
        if(i%j==0){
            count++;
        }
    }
    return count;
}
int main(){
    int a,b;
    cin>>a;
    int ans=0;
    for (int k=1;k<=a;k++){
        ans+=fuck(k);
    }
    cout<<ans<<endl;
    return 0;
}
//代码超时，建议使用筛法判断因数个数