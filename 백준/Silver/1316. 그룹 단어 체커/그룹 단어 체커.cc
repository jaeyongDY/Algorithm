#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solved() {
    int n, result = 0;
    string words;
    char temp;
    vector<char> check;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> words;
        check.clear();
        temp = 0;
        int j = 0;
        for(j = 0; j < words.length(); j++){
            if(temp != words[j]){
                auto it = find(check.begin(), check.end(), words[j]);
                if(it != check.end()){
                    break;
                }
                else{
                    check.push_back(words[j]);
                }
            }
            temp = words[j];
        }
        if(j == words.length()){
            result++;
        }
    }
    cout << result << endl;
}

int main(){
    solved();
    return 0;
}
