#include<bits/stdc++.h>
using namespace std;
bool sst(string a,string b){
    return (a + b >= b + a);
} 
int main(){
    int a;
    cin >> a;
    vector<string>b(a);
    for (int i = 0; i != a;i++){
        cin >> b[i];
    }
    sort(b.begin(), b.end(), sst);
    for (int i = 0; i != a;i++){
        cout << b[i];
    }
    return 0;
}