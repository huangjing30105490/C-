#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int count = 0;
    for(int m = 0; m < s.size(); m++ ){
        for(int n = m+1; n < s.size(); n++){
            if(s[m] == s[n]){
                int tem = m, tem1=n;
                while(tem++ < tem1--){
                    if(s[tem] != s[tem1]) break;
                }
                if(tem > tem1){
                    count = max(count, n-m+1);
                }
            }
        }
    }
    cout << count;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")
