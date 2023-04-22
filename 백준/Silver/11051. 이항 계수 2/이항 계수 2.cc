#include <iostream>
#include <memory.h>
#define MOD 10007

using namespace std;

int n, k;
int cache[1001][1001];

int dp(int n, int k) {
	if (k == 0 || k == n) return 1;

	if (cache[n][k] != -1) return cache[n][k];

	return cache[n][k] = (dp(n - 1, k - 1) + dp(n - 1, k)) % MOD;
}

int main() {
	cin >> n >> k;

	memset(cache, -1, sizeof(cache));
	cout << dp(n, k) % MOD;

	return 0;
}