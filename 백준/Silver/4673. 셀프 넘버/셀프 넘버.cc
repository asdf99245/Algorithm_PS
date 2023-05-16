#include <iostream>
#define endl '\n'

using namespace std;

bool arr[10001];

int d(int n) {
	int sum = n;

	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}

	return sum;
}

void solve() {
	for (int i = 1; i <= 10000; i++) {
		if (arr[i]) continue;
		int num = i;

		while (num <= 10000) {
			num = d(num);
			if (arr[num]) break;
			arr[num] = true;
		}
	}
}

int main() {
	solve();

	for (int i = 1; i <= 10000; i++) {
		if (arr[i]) continue;
		cout << i << endl;
	}

	return 0;
}