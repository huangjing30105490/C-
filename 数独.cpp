#include <bits/stdc++.h>
using namespace std;

int sudo[9][9];

bool isgood(int i, int j, int n) {
    //行；
    for (int y = 0; y < 9; y++) {
        if (sudo[i][y] == n) return false;
    }

    for (int x = 0; x < 9; x++) {
        if (sudo[x][j] == n) return false;
    }

    // for(int x = i; x<i+3; x++){
    //     for(int y = j; y < j+3; y++){
    //         if(sudo[x][y] == n) return false;
    //     }
    // }
    int startX = (i / 3) * 3;
    int startY = (j / 3) * 3;
    for (int x = startX; x < startX + 3; x++) {
        for (int y = startY; y < startY + 3; y++) {
            if (sudo[x][y] == n) return false;
        }
    }

    return true;
}

bool solvesudo() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudo[i][j] == 0) {
                for (int n = 1; n <= 9; n++) {
                    if (isgood(i, j, n)) {
                        sudo[i][j] = n;
                        if (solvesudo()) return true;
                        sudo[i][j] = 0;
                    }

                }
                return false; // 尝试所有数字都失败
            }
        }

    }

    return true;
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) cin >> sudo[i][j];
    }

    solvesudo();

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) cout << sudo[i][j] << ' ';
        puts(" ");
    }
}
// 64 位输出请用 printf("%lld")
