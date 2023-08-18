#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool valueSort(pair<int, int> &a, pair<int, int> &b){
    return a.second > b.second;
}

void solved() {
    vector<pair<int,int>> problem;
    int num[5];
    int score, sum = 0;
    for(int i =0; i < 8; i++){
        cin >> score;
        problem.push_back(make_pair(i+1, score));
    }
    sort(problem.begin(), problem.end(), valueSort);
    
    for(int i = 0; i < 5; i++){
        sum += problem[i].second;
        num[i] = problem[i].first;
    }
    sort(num, num+5);
    cout << sum << endl;
    for(auto result : num){
        cout << result << " ";
    }
    
}

int main(){
    solved();
    return 0;
}
