 #include<iostream>
#include<algorithm>

using namespace std;

void solved() {
    int n, rowResult = 0, colResult = 0;
    cin >> n;
    char total[101][101];
    
    
    for(int i = 0; i < n; i++){
        cin >> total[i];
    }
    
    // 가로
    for(int i = 0; i < n; i++){
        int check = 0;
        for(int j = 0; j < n; j++){
            if(total[i][j] == '.'){
                check++;
            }
            else if(total[i][j] == 'X'){
                if(check >= 2)
                    rowResult++;
                check = 0;
            }
            
            if(j == n - 1 && check >= 2){
                rowResult++;
            }
        }
    }
    
    // 세로
    for(int i = 0; i < n; i++){
        int check = 0;
        for(int j = 0; j < n; j++){
            if(total[j][i] == '.'){
                check++;
            }
            else if(total[j][i] == 'X'){
                if(check >= 2)
                    colResult++;
                check = 0;
            }
            if(j == n - 1 && check >= 2){
                colResult++;
            }
        }
    }
    
    cout << rowResult << " " << colResult << endl;
}

int main(){
    solved();
    return 0;
}
