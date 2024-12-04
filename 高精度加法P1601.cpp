#include<bits/stdc++.h>
using namespace std;
int aver[1001]={},bver[1001]={};
int main(){
    char a[1001]={0},b[1001]={0};
    int ans[1001]={};
    int alen,blen;
    cin>>a;//数1输入
    cin>>b;//数2输入
    alen=strlen(a);
    blen=strlen(b);
    for(int i=0;i!=alen;i++){
        aver[i]=a[alen-1-i]-'0';
    }
    for(int i=0;i!=blen;i++){
        bver[i]=b[blen-1-i]-'0';
    }
    for(int i=0;i!=max(alen,blen);i++){
        ans[i]=aver[i]+bver[i];
    }
    int mac=max(alen,blen);
    for(int i=0;i!=mac;i++){
        int pro;
        pro=ans[i];
        ans[i]%=10;
        pro-=ans[i];
        pro/=10;
        ans[i+1]+=pro;
    }
    int resLen = (ans[max(alen,blen)] > 0) ? max(alen,blen) + 1 : max(alen,blen);
    for (int i=resLen-1;i>=0;i--){
        cout<<ans[i];
    }
    return 0;
}
