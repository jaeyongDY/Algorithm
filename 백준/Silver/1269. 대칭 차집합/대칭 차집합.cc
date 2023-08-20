#include<iostream>
#include<algorithm>
#include<set>

using namespace std;
int a, b, cnt = 0;
set<int> check;

void input() {
    cin >> a >> b;
}

void solved() {
    int temp;
    
    for(int i = 0; i < a; i++){
        cin >> temp;
        check.insert(temp);
    }
    
    for(int i = 0; i < b; i++){
        cin >> temp;
        if(check.find(temp) != check.end()){
            cnt++;
        }
    }
    
}
void output() {
    cout << (a + b - 2*cnt) << endl;
}

int main(){
    input();
    solved();
    output();
    return 0;
}
