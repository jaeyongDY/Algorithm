#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

struct P {
    int x, y;
};

bool compare(P p1, P p2){
    if(p1.x == p2.x){
        return p1.y < p2.y;
    }
    return p1.x < p2.x;
}
long long distance(P p1, P p2){
    return pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2);
}

int main() {
    
    int t;
    P pointer[4];
    long long dis[4];
    
    cin >> t;
    
    for(int i = 0; i < t; i++){
        for(int j = 0;  j < 4; j++)
            cin >> pointer[j].x  >> pointer[j].y;
        
        sort(pointer, pointer + 4, compare);
        
        for(int i = 0; i < 4; i++){
            dis[i] = distance(pointer[i], pointer[i+1 == 4 ? 0 : i+1]);
        }
        if(distance(pointer[0], pointer[1]) == distance(pointer[0], pointer[2]) && distance(pointer[3], pointer[1]) == distance(pointer[3], pointer[2]) && distance(pointer[0],  pointer[3]) == distance(pointer[1], pointer[2])){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    
    
    return 0;
}
