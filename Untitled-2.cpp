#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    int b[10000000001]={};
    cin>>a;
    for (int i=0;i!=a;i++){
        cin>>b[i];
    }
    for (int i=0;i!=a;i++){
        for (int j=0;j!=a-i-1;j++){
            if(b[j]>=b[j+1]){
                int temp;
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }
    for (int i=0;i!=a;i++){
        cout<<b[i]<<" ";
    }
}