#include <iostream>

using namespace std;

int n, k;
int cache[31][31];

void bottomUp() {
	cache[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j == 1 || j == i) {
				cache[i][j] = 1;
				continue;
			}

			cache[i][j] = cache[i - 1][j - 1] + cache[i - 1][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	bottomUp();

	cout << cache[n][k];

	return 0;
}