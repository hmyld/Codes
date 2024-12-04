#include<bits/stdc++.h>
using namespace std;
int main(){
    char a[10]={};
    int b;
    cin>>a;
    b=strlen(a);
    stack <char> ans;
    for (int i=0;i!=b;i++){
        ans.push(a[i]);
    }
    while(1){
        cout<<ans.top();
        ans.pop();
        if(ans.size()==0)break;
    }
    return 0;
}