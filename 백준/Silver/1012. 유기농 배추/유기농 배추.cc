#include<iostream>
#include<string.h>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n,m;
int total[51][51];
bool check_visit[51][51];

bool dfs(int x, int y);

int main() {
    
    int t, k, x, y, warm;
    
    cin >> t;
    
    // 가로 m  <= 50
    // 세로 n <= 50
    
    while(t--){
        memset(total, 0, sizeof(total));
        memset(check_visit, 0, sizeof(check_visit));
        warm = 0;
        cin >> m >> n >> k;
        
        for(int i = 0; i < k; i++){
            cin >> x >> y;
            total[y][x] = 1;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                if(total[i][j] && !check_visit[i][j]) {
                    if(dfs(i,j)) {
//                        cout << " x : " << j << "y : " << i << '\n';
                        warm++;
                    }
                }
            }
        }
        cout << warm << '\n';
    }
    
    return 0;
}

bool dfs(int y, int x) {
    // 1의 값
    if(check_visit[y][x]) {
        return false;
    }
    check_visit[y][x] = true;
    for(int i = 0; i < 4; i++){
        int _y = dy[i] + y;
        int _x = dx[i] + x;
        if(_x >= 0 && _y >= 0 && _x < m && _y < n && total[_y][_x] == 1)
            dfs(_y, _x);
    }
    return true;
}
