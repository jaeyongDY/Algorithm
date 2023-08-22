#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
// x, y
int chess[6][6] = {0,};
string first, last;
bool check = true;

void input() {
    string input;
    string prev = "";
    for(int i = 1; i <= 36; i++){
        cin >> input;
        if(prev != ""){
            if(sqrt(pow((prev[0]-'A') - (input[0] - 'A'), 2) + pow((6 - (prev[1] - '0') - (6 - (input[1] - '0'))), 2)) != sqrt(5)){
                check = false;
            }
        }
        prev = input;
        
        int x = input[0] - 'A';
        int y = 6 - (input[1] - '0');
        if(i == 1) first = input;
        else if(i == 36) last = input;
        
        if(chess[x][y] == 1){
            check = false;
        }
        chess[x][y] = 1;
    }
}

void solved() {
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(chess[i][j] == 0){
                check = false;
            }
        }
    }
    int x1 = first[0] - 'A';
    int y1 = 6 - (first[1] - '0');
    int x2 = last[0] - 'A';
    int y2 = 6 - (last[1] - '0');
    if(sqrt(pow(x1-x2,2) + pow(y1-y2,2)) != sqrt(5)){
        check = false;
    }
}
void output() {
    cout << (check ? "Valid" : "Invalid") << endl;
}

int main(){
    input();
    solved();
    output();
    return 0;
}
