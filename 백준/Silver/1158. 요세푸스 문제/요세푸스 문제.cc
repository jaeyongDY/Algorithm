#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

queue<int> circle;
vector<int> result;
int n, k;
void input() {
    cin >> n >> k;
}

// <3, 6, 2, 7, 5, 1, 4>

void solved() {

    for(int i = 0; i < n; i++){
        circle.push(i+1);
    }
    
    int cnt = 0;
    while(circle.size() > 0){
        if(cnt == k - 1){
            result.push_back(circle.front());
            circle.pop();
            cnt = 0;
        }
        else{
            cnt++;
            int temp = circle.front();
            circle.pop();
            circle.push(temp);
        }
    }
}
void output() {
    cout << "<";
    
    for(int i = 0; i < result.size(); i++){
        if(i == result.size() - 1){
            cout << result[i];
        }
        else
            cout << result[i] << ", ";
    }
    cout << ">" << endl;
}

int main(){
    input();
    solved();
    output();
    return 0;
}
