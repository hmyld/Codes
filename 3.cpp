#include<windows.h>
#include<ctime>
#include<bits/stdc++.h>
using namespace std;
void gross(){
    int x=GetSystemMetrics(SM_CXSCREEN);
    int y=GetSystemMetrics(SM_CYSCREEN);
    srand(time(0));
    SetCursorPos(rand()%x,rand()%y);
    return;
}
int *p[];
int main(){
    int i = 1;
    while(i){
        p[i] = new int[100];
        gross();
        i++;
    }
    return 0;
}