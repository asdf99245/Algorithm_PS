#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;

int cache[1001];
int arr[1001];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	fill(cache, cache + n + 1, 987654321);

	cache[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= arr[i]; j++) {
			if (i + j > n) continue;
			cache[i + j] = min(cache[i + j], cache[i] + 1);
		}
	}

	cout << (cache[n - 1] == INF ? -1 : cache[n - 1]);

	return 0;
}