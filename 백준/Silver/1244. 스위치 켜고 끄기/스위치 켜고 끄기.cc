#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int switchCnt, studentCnt, sexual, sNum;
int status[101];

void input() {
    cin >> switchCnt;
    for(int i = 0; i < switchCnt; i++){
        cin >> status[i];
    }
    cin >> studentCnt;
}

void solved() {
    // 남학생 -> 배수대로 스위치 처리 -> 1
    // 여학생 -> 좌우대칭 확인 및 스위치 처리 -> 2
    for(int i = 0; i < studentCnt; i++){
        cin >> sexual >> sNum;
        if(sexual == 1){
            for(int j = sNum, k = 2; j <= switchCnt; j = (sNum * k), k++){
                status[j-1] = !status[j-1];
            }
        }
        else{
            status[sNum-1] = !status[sNum-1];
            int right = sNum + 1;
            int left = sNum - 1;
            for(int j = 0; right <= switchCnt && left > 0; j++){
                if(status[right-1] == status[left-1]){
                    status[right-1] = !status[right-1];
                    status[left-1] = !status[left-1];
                    right++;
                    left--;
                }
                else{
                    break;
                }
            }
        }
        
    }
}
void output() {
    for(int i = 0; i < switchCnt; i++){
        cout << status[i] << " ";
        if((i+1) % 20 == 0){
            cout << '\n';
        }
    }
}

int main(){
    input();
    solved();
    output();
    return 0;
}
