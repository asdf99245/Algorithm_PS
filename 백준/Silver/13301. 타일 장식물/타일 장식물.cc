#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;

ll cache[81];

/*
1, 1 * 2 + 1 * 2 = 4
2, 1 * 2 + 2 * 2 = 6
3, 2 * 2 + 3 * 2 = 10
4, 3 * 2 + 5 * 2 = 16
5, 26
*/

void bottomUp() {
	cache[1] = 4;
	cache[2] = 6;
	for (int i = 3; i <= N; i++) {
		cache[i] = cache[i - 1] + cache[i - 2];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	bottomUp();

	cout << cache[N];

	return 0;
}