#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> ts(9);
    int ans=0;
    for (int i = 0; i != 9;i=i){
        char t = getchar();
        if(t=='O'){
            ts[i] = 2;
            ans++;
            i++;
        }
        if(t=='X'){
            ts[i] = 1;
            ans++;
            i++;
        }
        if(t=='-'){
            i++;
        }
    }
    if(ts[1]==1&&ts[7]==2||ts[3]==1&&ts[5]==2||ts[5]==1&&ts[3]==2||ts[7]==1&&ts[1]==2){
        cout << "Dont know."<< endl << ans << endl;
        return 0;
    }
    if (ts[1] == 1 || ts[3] == 1 ||ts[5]==1||ts[7]==1){
        cout << "xiaoa will win." << endl << ans << endl;
        return 0;
    }
    cout << "Dont know."<< endl << ans << endl;
    return 0;
}