#include <iostream>

using namespace std;

bool check[1001];
int nums[1001];

int main() {
	int n;
	cin >> n;

	int curr = 0;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	for (int i = 0; i < n; i++) {
		int num = nums[curr];

		check[curr] = true;
		cout << curr + 1 << " ";
		if (i == n - 1) break;

		if (num < 0) {
			while (num != 0) {
				curr--;
				if (curr < 0) curr = n - 1;
				if (check[curr]) continue;
				num++;
			}
		}
		else {
			while (num != 0) {
				curr++;
				curr = curr % n;
				if (check[curr]) continue;
				num--;
			}
		}
	}


	return 0;
}