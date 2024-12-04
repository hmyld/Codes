#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
void making(const vector<string>& sto, vector<long long>& inspect) {
    for (string c : sto) {
        bool should_continue = false;
        long long hash_val = 0;
        for (char s : c) {
            hash_val = (hash_val * 31 + int(s)) % mod;     
        }
        for (int o : inspect) {
            if (o == hash_val) {
                should_continue = true;
                break;
            }
        }
        if (should_continue) {
            continue; 
        }
        inspect.push_back(hash_val);
    }
    return;
}
int main(){
    int n;
    cin >> n;
    vector<string> sto(n);
    for (int i = 0; i != sto.size();i++){
        cin >> sto[i];
    }
    vector<long long> inspect;
    making(sto, inspect);
    cout << inspect.size();
    return 0;
}