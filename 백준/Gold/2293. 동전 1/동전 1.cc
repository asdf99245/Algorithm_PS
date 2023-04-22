#include <iostream>

using namespace std;

int coin[101];
int cache[10001];

int main() {
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	cache[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j - coin[i] >= 0) {
				cache[j] += cache[j - coin[i]];
			}
		}
	}

	cout << cache[k];

	return 0;
}