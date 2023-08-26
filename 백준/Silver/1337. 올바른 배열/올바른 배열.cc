#include<iostream>
#include<algorithm>

using namespace std;
int n, cnt;
int t[51];
void input() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
}

void solved() {
    cnt = 1;
    
    sort(t, t + n);
    
    for(int i = 0; i < n ; i++){
        int k = 1;
        for(int j = i + 1; j < i + 5; j++){
            if(t[j] - t[i] < 5 && t[j] - t[i] > 0)
                k++;
        }
        cnt = max(cnt, k);
    }
}
void output() {
    if(cnt >= 5) cout << 0 << endl;
    else cout << 5 -  cnt << endl;
}

int main(){
    input();
    solved();
    output();
    return 0;
}
