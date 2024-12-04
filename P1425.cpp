#include<bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans1,ans2;
    ans1=c-a;
    ans2=d-b;
    if(ans2==60){
        ans2-=60;
        ans1++;
    }
    if(ans2<0){
        while(1){
            ans2+=60;
            ans1--;
            if(ans2>=0)break;
        }
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}