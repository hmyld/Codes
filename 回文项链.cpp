#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    int a;
    a=str.length();
    int j,k,ans;
    ans=a;
    k=a/2;
    j=k-1;
    while(1){
        if(str[k]!=str[j]){
            break;
        }else{
            j--;
            k++;
        }
        if (j>=0;a%2==0){
            a=a/2;
            k=a/2;
            j=k-1;
            ans/=2;
        }else{
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}