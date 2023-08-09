#include<iostream>
#include<algorithm>
using namespace std;

int main(){
   
    int n, row = 1, col = 1;
    
    cin >> n;
    
    
    while(true) {
        if((row + 1) * (col + 1) >= n) {
            break;
        }
        
        if((row + 2) * (col+1) >= (row + 1) * ((col + 2))){
            row++;
        }
        else{
            col++;
        }
    }
    
    cout << row * 2 + col * 2;
    return 0;
}
