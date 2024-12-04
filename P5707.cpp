#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c=60,d0;
    double d;
    cin>>a>>b;
    d0=a/b;
    d=double(a)/double(b);
    int e,f=7;
    if(d-(double)d0!=0.0){
        d0+=10;
        e=d0/60;
        d0%=60;
        f-=e;
        c-=d0;
        c-=1;
    }else{
        d0+=10;
        e=d/60;
        d0%=60;
        f-=e;
        c-=d0;
    }
    if (f<0){
        f+=24;
    }
    if(f>=10&&c>=10){
        printf("%d"":""%d",f,c);
    }else if(f<10&&c>=10){
        printf("0""%d"":""%d",f,c);
    }else if(f>=10&&c<10){
        printf("%d"":""0""%d",f,c);
    }else{
        printf("0""%d"":""0""%d",f,c);
    }
    return 0;
}