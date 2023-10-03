#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>

using namespace std;

string cycle(string input){
    string rtn;
    deque<char> _temp;
    for(auto i : input){
        _temp.push_back(i);
    }
    _temp.push_back(_temp.front());
    _temp.pop_front();
    for(auto i : _temp){
        rtn += i;
    }
    return rtn;
}

int main(){
    int n;
    bool check = false;
    vector<string> input;
    
    cin >> n;
    string temp;
    
    for(int i = 0; i < n; i++){
        
        cin >> temp;
        check = false;
        for(int j = 0; j < temp.length(); j++){
            if(find(input.begin(), input.end(), temp) != input.end()){
                check = true;
                break;
            }
            temp = cycle(temp);
        }
        if(!check){
            input.push_back(temp);
        }
    }
    
    cout << input.size() <<endl;
}
