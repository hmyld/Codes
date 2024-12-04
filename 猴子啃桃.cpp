#include<bits/stdc++.h>
using namespace std;
int ans=0;
int main(){
    int n,c,tgt[200005]={};
    cin>>n>>c;
    for(int i=0;i!=n;i++){
        cin>>tgt[i];
    }
    for(int j=0;j!=n;j++){
        for(int k=0;k!=n;k++){
            if(tgt[j]-tgt[k]==c){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}