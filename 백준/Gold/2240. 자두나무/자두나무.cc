#include <iostream>
#include <algorithm>

using namespace std;

int T, W;
int trees[1001];
int cache[31][1001][3];

void bottomUp() {
	for (int i = 0; i <= W; i++) {
		for (int j = 1; j <= T; j++) {
			int tree = trees[j];

			if (i == 0) {
				cache[i][j][1] = cache[i][j - 1][1] + (tree == 1);
				continue;
			}

			cache[i][j][1] = max(cache[i][j - 1][1] + (tree == 1), cache[i - 1][j - 1][2] + (tree == 1));
			cache[i][j][2] = max(cache[i][j - 1][2] + (tree == 2), cache[i - 1][j - 1][1] + (tree == 2));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T >> W;

	for (int i = 1; i <= T; i++) {
		cin >> trees[i];
	}

	bottomUp();

	int ans = 0;
	for (int i = 0; i <= W; i++) {
		ans = max(ans, max(cache[i][T][1], cache[i][T][2]));
	}

	cout << ans;

	return 0;
}