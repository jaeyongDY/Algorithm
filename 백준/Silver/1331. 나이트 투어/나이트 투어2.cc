#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

void prev_solved();
// x, y
int chess[6][6] = {0,};
string first, last, in, prev_check;
bool check = true;

void input() {
    prev_check = "";
    for(int i = 1; i <= 36; i++){
        cin >> in;
        if(i == 1) first = in;
        else if(i == 36) last = in;
        prev_solved();
    }
}

void prev_solved() {
    if(prev_check != ""){
        if(sqrt(pow((prev_check[0]-'A') - (in[0] - 'A'), 2) + pow((6 - (prev_check[1] - '0') - (6 - (in[1] - '0'))), 2)) != sqrt(5)){
            check = false;
        }
    }
    prev_check = in;
    
    int x = in[0] - 'A';
    int y = 6 - (in[1] - '0');
    
    if(chess[x][y] == 1){
        check = false;
    }
    chess[x][y] = 1;
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
