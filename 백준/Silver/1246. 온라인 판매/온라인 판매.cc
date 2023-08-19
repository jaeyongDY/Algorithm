#include<iostream>
#include<algorithm>

using namespace std;
int n,m;
int egg[1001];
int max_profit = 0;
int min_price;
bool compare(int i, int j){
    return i > j;
}
void input() {
    cin >> n >> m;
}

void solved() {
    // n : 달걀, m : 고객
    for(int i = 0 ; i < m; i++){
        cin >> egg[i];
    }
    sort(egg, egg + m, compare);
    
    int cnt = 0;
    while(true){
        if(cnt >= m || cnt >= n){
            break;
        }
        int price = egg[cnt] * (cnt+1);
        max_profit = max(max_profit, price);
        if(max_profit == price){
            min_price = egg[cnt];
        }
        cnt++;
    }
}
void output() {
    cout << min_price << " " << max_profit << endl;
}

int main(){
    input();
    solved();
    output();
    return 0;
}
