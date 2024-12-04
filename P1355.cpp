#include<bits/stdc++.h>
using namespace std;
#define int long long
int get_S(int a,int b,int c,int d,int e,int f) {
    int xx1 = a-e;
    int yy1 = b-f;
    int xx2 = c-e;
    int yy2 = d-f;
    int S2 = abs(xx1 * yy2 - xx2 * yy1);
    return S2;
}
signed main(){
    vector<int> x(4);
    vector<int> y(4);
    char ch;
    for (int i = 0; i < 4; i++) {
        cin >> ch >> x[i] >> ch >> y[i] >> ch;
    }
    if(x[3]==x[0]&&y[3]==y[0]||x[3]==x[1]&&y[3]==y[1]||x[3]==x[2]&&y[3]==y[2]){
        cout << 4 << endl;
        return 0;
    }
    vector<int> x1(3);
    vector<int> y1(3);
    for (int i = 0; i != 3;i++){
        x1[i] = x[i] - x[3];
        y1[i] = y[i] - y[3];
    }
    if(y1[0]*x1[1]==y1[1]*x1[0]&&x1[1]*x1[0] < 0||y1[2]*x1[1]==y1[1]*x1[2]&&x1[1]*x1[2]<0||y1[0]*x1[2]==y1[2]*x1[0]&&x1[2]*x1[0]<0){
        cout << 3 << endl;
        return 0;
    }
    if(y1[0]*x1[1]==y1[1]*x1[0]&&y1[0]*x1[0] < 0||y1[2]*x1[1]==y1[1]*x1[2]&&x1[1]*y1[1]<0||y1[0]*x1[2]==y1[2]*x1[0]&&x1[2]*y1[2]<0){
        cout << 3 << endl;
        return 0;
    }
    int ss = get_S(x[1], y[1], x[2], y[2], x[0], y[0]);
    int ss1 = get_S(x[1], y[1], x[2], y[2], x[3], y[3]) + get_S(x[0], y[0], x[2], y[2], x[3], y[3]) + get_S(x[1], y[1], x[0], y[0], x[3], y[3]);
    if(ss1==ss){
        if(get_S(x[1], y[1], x[2], y[2], x[3], y[3])==0||get_S(x[0], y[0], x[2], y[2], x[3], y[3])==0||get_S(x[1], y[1], x[0], y[0], x[3], y[3])==0){
            cout << 3 << endl;
            return 0;
        }
    }
    if(ss1==ss){
        cout << 1 << endl;
        return 0;
    }
    cout << 2 << endl;
    return 0;
}