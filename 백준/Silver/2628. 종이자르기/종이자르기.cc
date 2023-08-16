#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solved() {
    int row, col, n, a, b;
    int p[101][101];
    vector<int> c;
    vector<int> r;
    
    
    cin >> col >> row;
    cin >> n;
    
    for(int i = 0; i < n ; i++){
        cin >> a >> b;
        if(a == 0)
            r.push_back(b);
        else
            c.push_back(b);
    }
    sort(r.begin(), r.end());
    sort(c.begin(), c.end());
    
    int temprow = 0, maxrow = 0;
    int tempcol = 0, maxcol = 0;
    for(auto _r : r){
        maxrow = max(maxrow, _r - temprow);
        temprow = _r;
    }
    maxrow = max(maxrow, row - temprow);
    for(auto _c : c){
        maxcol = max(maxcol, _c - tempcol);
        tempcol = _c;
    }
    maxcol = max(maxcol, col - tempcol);
    cout << maxrow * maxcol << endl;
}

int main(){
    solved();
    return 0;
}
