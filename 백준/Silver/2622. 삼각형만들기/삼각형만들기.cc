#include<iostream>
#include<algorithm>
using namespace std;

void solved() {
    int n, result = 0;
    cin >> n;
    
    // a,b,c => a+b > c
    for(int a = 1; a < n; a++){
        for(int b = a; b < n; b++){
            int c = n - (a + b);
            if(b > c) break;
            if(a+b > c){
                result++;
            }
        }
    }
    cout << result << endl;
}

int main(){
    solved();
    return 0;
}
