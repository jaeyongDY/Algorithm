#include<iostream>

using namespace std;

int main() {

	int n, m, result = 0;

	cin >> n >> m;

	char p[51][51];

	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	// 1. -
	int tempCnt;
	for (int i = 0; i < n; i++) {
		tempCnt = 0;
		for (int j = 0; j < m; j++) {
			if (tempCnt > 0 && p[i][j] == '|') {
				result++;
				tempCnt = 0;
				continue;
			}

			if (p[i][j] == '-')
				tempCnt++;
		}
		if (tempCnt > 0)
			result++;
	}
	// 2. |
	for (int i = 0; i < m; i++) {
		tempCnt = 0;
		for (int j = 0; j < n; j++) {
			if (tempCnt > 0 && p[j][i] == '-') {
				result++;
				tempCnt = 0;
				continue;
			}
			if(p[j][i] == '|')
				tempCnt++;
		}
		if (tempCnt > 0)
			result++;
	}

	cout << result << endl;

	return 0;
}