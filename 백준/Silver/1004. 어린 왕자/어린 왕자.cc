#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int t, x1, y1, x2, y2, n, result;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        result = 0;
        for (int j = 0; j < n; j++) {
            int a, b, r;
            cin >> a >> b >> r;

            int distance1 = pow(a - x1, 2) + pow(b - y1, 2);
            int distance2 = pow(a - x2, 2) + pow(b - y2, 2);
            int pow_r = pow(r, 2);
            
            if (distance1 < pow_r && distance2 < pow_r) {
                continue;
            }

            if (distance1 < pow_r || distance2 < pow_r) {
                result++;
                continue;
            }   
        }
        cout << result << endl;
    }
    
    
    return 0;
}
