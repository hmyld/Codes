#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,r;
    cin>>h>>r;
    double inspect;
    const double PI=3.14,g=20000.0;
    inspect=(double)((PI*r*r*h));
    inspect=g/inspect;
    int insplus;
    insplus=(int)inspect;

    if (inspect-insplus==0.0){
        cout<<insplus<<endl;
        return 0;
    }
    cout<<insplus+1<<endl;
    return 0;
}