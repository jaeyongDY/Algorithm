#include<iostream>
#include<algorithm>
using namespace std;


int main() {
    
    int n, r, g, b;
    int color[1001][3];
    color[0][0] = 0;
    color[0][1] = 0;
    color[0][2] = 0;
    cin >> n;
    
    for(int i = 1; i < n+1; i++) {
        cin >> r >> g >> b;
        color[i][0] = min(color[i-1][1], color[i-1][2]) + r;
        color[i][1] = min(color[i-1][0], color[i-1][2]) + g;
        color[i][2] = min(color[i-1][1], color[i-1][0]) + b;
    }
    cout << min({color[n][0], color[n][1], color[n][2]});
    return 0;
}
