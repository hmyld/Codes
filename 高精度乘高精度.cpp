#include<bits/stdc++.h>
using namespace std;
int main(){
    char ainput[10001]={},binput[10001]={};
    int aver[10001]={},bver[1000]={};
    cin>>ainput;
    cin>>binput;
    int alen,blen;
    //变量声明
    alen=strlen(ainput);
    blen=strlen(binput);
    for(int i=0;i!=alen;i++){
        aver[i]=ainput[alen-1-i]-'0';
    }
    for(int i=0;i!=blen;i++){
        bver[i]=binput[blen-1-i]-'0';
    }
    //输入反录入数组
    int ans[100001]={};
    int a=0;
    for (int i=0;i!=alen;i++){
        a++;
        for (int j=0;j!=blen;j++){
            ans[i+j]+=aver[i]*bver[j];
        }
    }
    //竖式乘法，以alen长度保存；
    for(int i=0;i!=alen+a;i++){
        int pro;
        pro=ans[i];
        ans[i]%=10;
        pro/=10;
        ans[i+1]+=pro;
    }
    //最后一位不用管
    while(1){
        if(ans[a+alen-1]==0){
            a--;
        }
        if(ans[a+alen-1]!=0||a+alen-1==0)break;
    }
    for (int i=a+alen-1;i>=0;i--){
        cout<<ans[i];
    }
    return 0;
}