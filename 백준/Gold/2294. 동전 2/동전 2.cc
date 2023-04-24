#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;

int n, k;
int coins[101];
int cache[100001];

bool compare(int a, int b) {
	return a > b;
}

void bottomUp() {
	cache[0] = 0;
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i - coins[j] < 0) continue;

			cache[i] = min(cache[i], cache[i - coins[j]] + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	sort(coins, coins + n, compare);

	fill(cache, cache + k + 1, INF);

	bottomUp();

	cout << (cache[k] == INF ? -1 : cache[k]);

	return 0;
}