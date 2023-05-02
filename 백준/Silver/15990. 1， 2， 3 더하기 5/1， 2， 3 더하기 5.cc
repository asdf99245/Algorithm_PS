#include <iostream>
#include <algorithm>
#define MOD 1000000009

using namespace std;

typedef long long ll;

int n;
ll cache[100001][4];

void bottomUp() {
	cache[1][1] = cache[2][2] = cache[3][1] = cache[3][2] = cache[3][3] = 1;
	for (int i = 4; i <= 100000; i++) {
		cache[i][1] = (cache[i - 1][2] + cache[i - 1][3]) % MOD;
		cache[i][2] = (cache[i - 2][1] + cache[i - 2][3]) % MOD;
		cache[i][3] = (cache[i - 3][1] + cache[i - 3][2]) % MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	bottomUp();

	while (T--) {
		cin >> n;
		cout << (cache[n][1] + cache[n][2] + cache[n][3]) % MOD << '\n';
	}

	return 0;
}