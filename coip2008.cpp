#include<bits/stdc++.h>
using namespace std;
int main() {
    int sum=0;
    int col[10]={6,2,5,5,4,5,6,3,7,6},n;
    cin>>n;
    for(int i=0;i!=1000;i++){
        for(int k=0;k!=1000;k++){
            if (col[i]+col[k]+col[i+k]+4=n){
                sum++;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}