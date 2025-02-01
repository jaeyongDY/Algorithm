#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define MAX  1000000000;
#define MIN -1000000000;

using namespace std;

void input();
void solve();
void backTracking(int current, int num, int plus, int minus, int multi, int division);

int N;
vector<int> A;
map<int, int> operData;

int maxResult = MIN;
int minResult = MAX;

int main() {
	
	input();
	solve();
	return 0;
}

void input() {
	cin >> N;

	A.assign(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int data;
	for (int i = 0; i < 4; i++) {
		cin >> data;
		operData.insert({ i + 1, data });
	}
}

void solve() {
	
	backTracking(1, A[0], operData[1], operData[2], operData[3], operData[4]);

	cout << maxResult << " " << minResult << endl;

}

void backTracking(int current, int num, int plus, int minus, int multi, int division) {

	if (current == A.size()) {
		maxResult = max(maxResult, num);
		minResult = min(minResult, num);
		return;
	}
	
	if (plus != 0) {
		backTracking(current + 1, num + A[current], plus - 1, minus, multi, division);
	}

	if (minus != 0) {
		backTracking(current + 1, num - A[current], plus, minus - 1, multi, division);
	}

	if (multi != 0) {
		backTracking(current + 1, num * A[current], plus, minus, multi - 1 , division);
	}

	if (division) {
		backTracking(current + 1, num / A[current], plus, minus, multi, division - 1);
	}
}