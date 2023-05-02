#include <iostream>
#include <algorithm>
#define endl '\n';

using namespace std;

int coins[21];
int cache[10001];

int bottomUp(int n, int m) {
	fill(cache, cache + m + 1, 0);

	cache[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= m; j++) {
			cache[j] += cache[j - coins[i]];
		}
	}

	return cache[m];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	int n, m;
	while (T--) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> coins[i];
		}

		cin >> m;

		cout << bottomUp(n, m) << endl; 
	}

	return 0;
}