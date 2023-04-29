#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;

int n;

int cache[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int coins[2] = { 5, 2 };

	cin >> n;

	fill(cache, cache + n + 1, INF);

	cache[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			if (i - coins[j] < 0) continue;

			cache[i] = min(cache[i], cache[i - coins[j]] + 1);
		}
	}

	cout << (cache[n] != INF ? cache[n] : -1);

	return 0;
}