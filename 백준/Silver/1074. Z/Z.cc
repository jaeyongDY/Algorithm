#include<iostream>
using namespace std;

int n, c, r, result;

void Z(int x, int y, int size) {

    if(y == r && x == c) {
        cout << result;
        return;
    }

    if(c < x + size && c >= x && r < y + size && r >= y) {
        Z(x, y, size / 2);
        Z(x + size / 2, y, size / 2);
        Z(x, y + size / 2, size / 2);
        Z(x + size / 2, y + size / 2, size / 2);
    }
    else {
        result += size * size;
    }

}

int main() {

    // r행 c열
    cin >> n >> r >> c;  

    Z(0, 0, (1 << n));

    return 0;
}
