#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void input();
void solve();

int N;

vector<int> nums;

int main() {
	
	input();
	solve();

	return 0;
}


void input() {
	cin >> N;

	nums.assign(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	
}

void solve() {
	if (N == 1) {
		cout << "A" << endl;
		return;
	}
	else if (N == 2) {
		if (nums[0] - nums[1] == 0) {
			cout << nums[0] << endl;
			return;
		}
		else {
			cout << "A" << endl;
			return;
		}
	}
	else if (N >= 3) {
		int A = nums[0];
		int B = nums[1];
		int C = nums[2];

		int a;
		if (B - A == 0) {
			a = 0;
		}
		else {
			a = (C - B) / (B - A);
			if ((C - B) % (B - A) > 0) {
				cout << "B" << endl;
				return;
			}
		}
		
		int b = B - (a * A);
		bool isNext = true;
		for (int i = 0; i < nums.size()-1; i++) {
			isNext = ((nums[i] * a + b) == nums[i+1]);
			if (!isNext) {
				cout << "B" << endl;
				return;
			}
		}
		cout << nums[nums.size() - 1] * a + b << endl;
	}
}
