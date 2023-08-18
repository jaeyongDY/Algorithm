#include<iostream>
#include<algorithm>
using namespace std;

void solved() {
    int m,n,j,pos,apple,cnt;
    
    cin >> n >> m;
    cin >> j;
    
    pos = 1;
    cnt = 0;
    for(int i = 0; i < j; i++){
        cin >> apple;
        
        while(true){
            if(abs(pos - apple) < m && apple >= pos){
                break;
            }
            if(abs(pos - apple + 1) > abs(pos - apple - 1)){
                pos--;
            }
            else {
                pos++;
            }
            cnt++;
        }
    }
    
    cout << cnt << endl;
}

int main(){
    solved();
    return 0;
}
