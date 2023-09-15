#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
void input();
void solved();
void output();
int findPos(deque<int> param1, int value);
deque<int> _deque;
int n, m, result;
int want[51] = { 0, };

int main() {
    input();
    solved();
    output();
    return 0;
}
void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        _deque.push_back(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> want[i];
    }
}

void solved() {
    for (int i = 0; i < m; i++) {
        int cur = want[i];
        while (true) {
            int num = findPos(_deque, cur);
            if (num == -1)
                break;
            bool direction = (_deque.size() / 2) >= num ? false : true;
            if (num == 0) {
                _deque.pop_front();
                continue;
            }

            if (!direction) {
                _deque.push_back(_deque.front());
                _deque.pop_front();
                result++;
            }
            else {
                _deque.push_front(_deque.back());
                _deque.pop_back();
                result++;
            }
        }
    }
}

int findPos(deque<int> param1, int value) {
    auto it = find(param1.begin(), param1.end(), value);
    if (it == param1.end()) {
        return -1;
    }
    
    for (int i = 0; i < param1.size(); i++) {
        if (value == param1[i])
            return i;
    }
}

void output() {
    cout << result;
}
