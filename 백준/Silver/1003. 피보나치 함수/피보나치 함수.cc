#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int cache[41][2];

int dp(int n, int target) {
	if (cache[n][target] != -1) return cache[n][target];


	return cache[n][target] = dp(n - 1, target) + dp(n - 2, target);
}

int main() {
	int T, N;
	cin >> T;

	while (T-- > 0) {
		cin >> N;
		memset(cache, -1, sizeof(cache));
		cache[0][0] = 1;
		cache[0][1] = 0;
		cache[1][0] = 0;
		cache[1][1] = 1;
		dp(N, 0);
		dp(N, 1);

		cout << cache[N][0] << ' ' << cache[N][1] << '\n';
	}

	return 0;
}