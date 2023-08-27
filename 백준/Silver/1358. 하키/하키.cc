#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
int w,h,x,y,p,result;

void input() {
    cin >> w >> h >> x >> y >> p;
}

void solved() {
    // radius = h / 2
    int tx, ty;
    result = 0;
    for(int i = 0; i < p; i++){
        cin >> tx >> ty;
        
        // 1. 직사각형 체크
        if(ty >= y && ty <= (y+h)){
            if(tx >= x && tx <= (x + w)){
                result++;
            }
            if(tx < x || tx > (x+w)){
                if(sqrt(pow(x - tx, 2) + pow(ty - (y + (h / 2)), 2)) <= sqrt(pow(h/2,2))||
                   sqrt(pow((x + w) - tx, 2) + pow(ty - (y + (h / 2)), 2)) <= sqrt(pow((h/2),2))){
                    result++;
                }
            }
        }
    }
}
void output() {
    cout << result << endl;
}

int main(){
    input();
    solved();
    output();
    return 0;
}
