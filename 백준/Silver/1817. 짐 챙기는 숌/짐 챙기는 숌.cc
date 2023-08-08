#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int result = 0, sum = 0;
    
    int books[51] = {0,};
    
    for(int i =0; i < n ; i++){
        cin >> books[i];
    }
    
    for(int i = 0; i < n; i++){
        sum += books[i];
        if(sum > m){
            result++;
            sum = books[i];
        }
    }
    if(sum != 0) result++;
    
    cout << result <<endl;
    
    return 0;
}
