#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){

    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};
    
    int map = 0;

    cin >> map;
    
    char total[1001][1001];
    char result[1001][1001];
    for(int i=0; i < map; i++){
        cin >> total[i];
    }
    
    for(int i = 0; i < map; i++){
        for(int j = 0; j < map; j++){
            if(total[i][j] != '.') {
                result[i][j] = '*';
                continue;
            }
            int num = 0;
            for(int chk = 0; chk < 8; chk++){
                int nr = dx[chk] + i;
                int nc = dy[chk] + j;
                if(nr < 0 || nr >= map || nc < 0 || nc >= map) {continue;}
                if(total[nr][nc] == '.') {continue;}
                num += total[nr][nc] - '0';
            }
            if(num >= 10) result[i][j] = 'M';
            else result[i][j] = num + '0';
        }
    }
    for(int k = 0; k <map; k++){
        cout << result[k] <<endl;
    }
    
    
    return 0;
}

                           
