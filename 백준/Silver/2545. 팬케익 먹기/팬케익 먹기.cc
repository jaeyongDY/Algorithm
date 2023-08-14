#include<iostream>
#include<algorithm>

using namespace std;

void sort(int *a, int *b, int *c){
    vector<int> temp;
    temp.push_back(*a);
    temp.push_back(*b);
    temp.push_back(*c);
    sort(temp.begin(), temp.end());
    for(int i =0 ; i < temp.size(); i++){
        int num = temp[i];
        switch(i){
            case 0 :
                *a = num;
                break;
            case 1 :
                *b = num;
                break;
            case 2 :
                *c = num;
                break;
        }
    }
    
}

void solved() {
    // 제한 0 <= D <= A+B+C-3
    int t,a,b,c,d,temp;
    cin >> t;
    
    for(int i =0; i < t; i++){
        cin >> a >> b >> c >> d;
        sort(&a, &b, &c);
        int s = a + b + c - d;
        temp = min(s / 3, a);
        int tempA = temp;
        s -= temp;
        temp = min(s / 2, b);
        
        cout << tempA * temp * (s-temp) << endl;
    }
    
}

int main(){
    solved();
    return 0;
}
