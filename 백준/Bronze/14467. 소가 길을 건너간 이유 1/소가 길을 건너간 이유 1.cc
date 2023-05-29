#include <iostream>
#include <algorithm>

using namespace std;

int cows[101];

int main() {
	int n;
	cin >> n;

	int cnt = 0;
	fill(cows, cows + n + 1, -1);
	for (int i = 0; i < n; i++) {
		int num, pos;
		cin >> num >> pos;
		if (cows[num] == -1) { 
			cows[num] = pos; 
		}
		else if (cows[num] != pos) {
			cows[num] = pos;
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}