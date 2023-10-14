#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    
    long long n, t, s, l, c;
    vector<long long> bus;
    cin >> n >> t;
    

    for(int i = 0 ; i < n; i++){
        cin >> s >> l >> c;
        for(int j = 0; j < c; j++){
            bus.push_back(s + (j * l));
        }
    }
    
    sort(bus.begin(), bus.end());
    
    int f = 0, e = bus.size();
    
    while(f < e) {
        int m = (f + e) / 2;
        
        if(bus[m] - t >= 0) {
            e = m;
        }
        else{
            f = m+1;
        }
    }
    if(bus[f] - t < 0) {
        cout << - 1 << endl;
    }
    else{
        cout << bus[f] - t << endl;
    }
    return 0;
}
