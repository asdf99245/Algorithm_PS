#include <iostream>
#include <algorithm>
#define MAX 1000000000

using namespace std;

typedef long long ll;
int n, m, k;
ll cache[101][101];

void dp() {
	cache[0][0] = 0;

	for (int i = 1; i <= n; i++) cache[i][0] = 1;
	for (int i = 1; i <= m; i++) cache[0][i] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cache[i][j] = cache[i - 1][j] + cache[i][j - 1];
			if (cache[i][j] > MAX) cache[i][j] = MAX;
		}
	}
}

void printWord() {
	int a = n;
	int z = m;

	for (int i = 0; i < n + m; i++) {
		ll a_start = cache[a - 1][z];

		if (a == 0) {
			cout << 'z';
			z--;
		}
		else if (z == 0) {
			cout << 'a';
			a--;
		}
		else if (k > a_start) {
			cout << 'z';
			k -= a_start;
			z--;
		}
		else if (k <= a_start) {
			cout << 'a';
			a--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;

	dp();

	if (cache[n][m] < k) {
		cout << -1;
		return 0;
	}

	printWord();

	return 0;
}