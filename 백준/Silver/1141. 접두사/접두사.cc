#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

bool cmp(const string a, const string b) {
    return a.length() < b.length();
}

int main() {
    
    int n;
    
    string words[51];
    string word;
    int cnt = 0;
    cin >> n;
    
    bool result[51];
    memset(result, true, sizeof(result));
    
    for(int i = 0; i < n; i++) {
        cin >> word;
        words[i] = word;
    }
    sort(words, words + n, cmp);
    
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(words[j].substr(0,words[i].length()) == words[i]) {
                result[i] = false;
                break;
            }
        }
    }

    for(int i = 0; i < n ; i++) {
        if(result[i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
