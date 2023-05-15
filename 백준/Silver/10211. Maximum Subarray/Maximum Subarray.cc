#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

int arr[1001];
int cache[1001];

int bottomUp(int n) {
	cache[0] = arr[0];

	int maxv = arr[0];

	for (int i = 1; i < n; i++) {
		cache[i] = max(arr[i], cache[i - 1] + arr[i]);
		maxv = max(maxv, cache[i]);
	}

	return maxv;
}

int main() {
	int T;

	cin >> T;

	while (T--){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		cout << bottomUp(n) << endl;
	}

	return 0;
}