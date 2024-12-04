#include<bits/stdc++.h>
using namespace std;
int main(){
    double a,b,c,p;
    cin>>a>>b>>c;
    p=(a+b+c)/2;
    p=p*(p-a)*(p-b)*(p-c);
    p=sqrt(p);
    printf("%0.1f",p);
    return 0;
}