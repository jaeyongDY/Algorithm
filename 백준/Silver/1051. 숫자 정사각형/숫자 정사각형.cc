#include<iostream>
#include<algorithm>
using namespace std;
void input();
void solved();
void output();

int n, m, result = 1;
int square[51][51];
bool check = false;

int main() {
    input();
    solved();
    output();
    return 0;
}
void input() {
    cin >> n >> m;
    string temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (int j = 0; j < m; j++) {
            square[i][j] = temp[j] - '0';
        }
    }
}

void solved() {
    int _min = min(n, m);

    for (int i = _min - 1; i > 0 && !check; i--) {

        for (int x = 0; x < n - i; x++) {
            for (int y = 0; y < m - i; y++) {
                if (square[x][y] == square[x + i][y] && square[x][y + i] == square[x + i][y + i]
                    && square[x][y] == square[x + i][y + i] && square[x + i][y] == square[x][y + i]) {
                    check = true;
                    result = i+1;
                }
            }
        }
    }
}

void output() {
    cout << result * result << endl;
}
