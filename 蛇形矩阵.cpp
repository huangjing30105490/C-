#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int main() {
    int a[N][N] = {0};
    int x;
    cin >> x;
    int n = (x*(x+1))/2;
    int h = 2, l = 1;
    a[1][1] = 1;
    for(int i = 2; i <= n;){
        int tem = h;
        while(tem){
            a[tem][l++] = i++;
            tem--;
        }
        if(tem == 0){
            h++;
            l = 1;
        }
    }

    for(int i = 1; i<=x; i++ ){
        for(int j = 1; j <= x; j++){
            if(a[i][j] != 0) cout<< a[i][j] << ' ';
        }
        cout << endl;
    }
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")
