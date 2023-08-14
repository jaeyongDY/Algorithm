#include<iostream>
#include<algorithm>

using namespace std;

void solved() {
    int x, stick = 64, result = 1, sum = 0;
    cin >> x;
    
    sum = stick;
    while(true){
        if(x == sum){
            break;
        }
        stick /= 2;
        if(sum > x){
            sum = stick;
            result = 1;
        }
        else{
            if(sum + stick > x){
                continue;
            }
            sum += stick;
            result++;
        }
    }
    cout << result << endl;
}

int main(){
    solved();
    return 0;
}
