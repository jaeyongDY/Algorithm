#include<iostream>
#include<algorithm>
using namespace std;

long long factorial(int n);

int main(){
    
    long long n;
    long long checkList[20];
    cin >> n;
    
    for(int i = 19; i >= 0 ; i--){
        checkList[i] = factorial(i);
    }
    
    if(n == 0){
        cout << "NO" <<endl;
    }
    else{
        for(int i = 19; i >= 0 ; i--){
            if(checkList[i] <= n)
                n -= checkList[i];
        }
        cout << (n != 0 ? "NO" : "YES") << endl;
    }
    return 0;
}

long long factorial(int n) {
    if(n == 0){
        return 1;
    }
    return n * factorial(n-1);
}
