#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    map<char, int> m;
    for(auto & i : s){
        m[i]++;
    }

    int min_len = s.size();
    for(auto & p : m){
        min_len = min(min_len, p.second); 
    }
    for(auto & p : s){
        if(m[p] == min_len){
            continue;
        }
        cout << p;
    }

    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")
