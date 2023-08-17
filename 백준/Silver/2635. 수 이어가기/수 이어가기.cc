#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

void solved() {
    int n;
    cin >> n;
    
    map<int, vector<int>> q;
    
    int check = 0, maxcnt = 0, cnt;
    map<int, vector<int>>::iterator it;

    for(int i = 1; i <= n; i++){
        q.insert({i, vector<int>()});
        it = q.find(i);
        it->second.push_back(n);
        it->second.push_back(i);
        cnt = 2;
        while(true){
            int one = it->second[cnt - 2];
            int two = it->second[cnt - 1];
            if(one - two < 0) break;
            it->second.push_back(one - two);
            cnt++;
        }
        maxcnt = max(maxcnt, (int)it->second.size());
        if(maxcnt == (int)it->second.size())
            check = it -> first;
    }
    
    cout << maxcnt << endl;
    it = q.find(check);
    for(auto result : it -> second){
        cout << result << " ";
    }
}

int main(){
    solved();
    return 0;
}
