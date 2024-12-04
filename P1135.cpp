#include<bits/stdc++.h>
using namespace std;
int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {  
        if (ch == '-') w = -1;
        ch = getchar();       
    }
    while (ch >= '0' && ch <= '9') {  
        x = x * 10 + (ch - '0');  
        ch = getchar();           
    }
    return x * w;  
}
void write(int x) {
    if (x < 0) { 
        x = -x;  
        putchar('-'); 
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
int bfs(vector<int> &a, int M, int N) {
    vector<int> ans(a.size(),-1);
    queue<pair<int, int>> qqqqq;
    ans[M] = 0;
    qqqqq.push({M, a[M]});
    while(!qqqqq.empty()){
        pair<int, int> need = qqqqq.front();
        qqqqq.pop();
        if(need.first + need.second < a.size() && ans[need.first + need.second]==-1){
            ans[need.first + need.second] = ans[need.first] + 1;
            qqqqq.push({need.first + need.second, a[need.first + need.second]});
        }
        if(need.first - need.second > 0 && ans[need.first - need.second]==-1){
            ans[need.first - need.second] = ans[need.first] + 1;
            qqqqq.push({need.first - need.second, a[need.first - need.second]});
        }
        if(ans[N]!=-1){
            return ans[N];
        }
    }
    return -1;
}
int main(){
    int A, M, N;
    A = read();
    M = read();
    N = read();
    vector<int> a(A+1);
    for (int i = 1; i != A+1; i++) {
        a[i] = read();
    }
    int ans;
    ans=bfs(a,M,N);
    write(ans);
    return 0;
}