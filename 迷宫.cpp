#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int h, w;
int a[N][N];
int px[N][N], py[N][N];  // 记录每个节点的前驱节点坐标
bool visited[N][N] = {false};
const int dx[4] = {-1, 1, 0, 0};  // 上、下、左、右四个方向
const int dy[4] = {0, 0, -1, 1};
vector<pair<int , int>> r;

bool isnull(int x, int y){
    return x >= 0 && x < h && y >= 0 && y < w && !visited[x][y]&& a[x][y]==0;
}

void dfs(){
    queue<pair<int, int>> q;
    q.push({0, 0});//起点
    visited[0][0] = {true};
    px[0][0] = -1;
    py[0][0] = -1;

    
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == h - 1 && y == w - 1) {
            return;
        }

        for(int i=0; i< 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(isnull(nx, ny)){
                visited[nx][ny] = true;
                px[nx][ny] = x;
                py[nx][ny] = y;
                q.push({nx, ny});

            }
        }


    }

}

void coutpath(){
    vector<pair<int, int>> path;
    int x = h-1;
    int y = w-1;
    
    // 从终点回溯到起点
    while (x != -1 || y != -1) {
        path.push_back({x, y});
        int tempX = px[x][y];
        int tempY = py[x][y];
        x = tempX;
        y = tempY;
    }
    
    // 逆序输出路径（从起点到终点）
    for (int i = path.size() - 1; i >= 0; i--) {
        cout<<'(' << path[i].first << "," << path[i].second << ')' << endl;
    }

}

int main() {

    cin >> h >> w;

    for(int i = 0; i<h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }
    dfs();
    coutpath();
}
// 64 位输出请用 printf("%lld")
