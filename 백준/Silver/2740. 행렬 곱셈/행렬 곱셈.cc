#include<iostream>
#include<algorithm>
using namespace std;

void solved() {
    int n, m, k;
    int p[101][101];
    int r[101][101];
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> p[i][j];
        }
    }
    cin >> m >> k;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < k; j++){
            cin >> r[i][j];
        }
    }
     
    
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < k; j++){
            int sum = 0;
            for(int cnt = 0; cnt <m; cnt++){
                sum += (p[i][cnt] * r[cnt][j]);
            }
            cout << sum << " ";
        }
        cout << '\n';
    }
}

int main(){
    solved();
    return 0;
}
