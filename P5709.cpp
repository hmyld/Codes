#include<bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c,d;
    cin>>a>>b>>c;
    if(b==0){
        cout<<0<<endl;
        return 0;
    }
    double ww;
    ww=1.0*c/b;
    
    d=c/b;
    a-=d;
    if(a<0){
        a=0;
    }
    if (ww-(double)d!=0&&a>0){
        a--;
        cout<<a<<endl;
        return 0;
    }
    cout<<a<<endl;
    return 0;
}