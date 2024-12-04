#include<bits/stdc++.h>
using namespace std;
int f(char inst) {
    int j;
    cin>>inst;
    j=static_cast<int>(inst);
    j-=65;
    return j;
}
int main() {
    char s,t;
    int as,at,tt;
    as=f(s);
    at=f(t);
    tt=as+at;
    char ans,ans10,ans0;
    if (tt>=26){
        int te,ze;
        for (int i=0,k=0;tt>=26;i++){
            tt-=26;
            k++;
            te=k;
            ze=tt;
        }
        te+=65;
        ze+=65;
        ans10=static_cast<char>(te);
        ans0=static_cast<char>(ze);
        printf("%c%c",ans10,ans0);
    }else{
        tt+=65;
        ans=static_cast<char>(tt);
        cout<<ans<<endl;
    }
    return 0;
}