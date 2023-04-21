#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

long long cache[101];

int main() {
	int T, N;
	cin >> T;

	memset(cache, -1, sizeof(cache));
	cache[1] = cache[2] = cache[3] = 1;
	for (int i = 4; i <= 100; i++) {
		cache[i] = cache[i - 2] + cache[i - 3];
	}

	while (T-- > 0) {
		cin >> N;

		cout << cache[N] << '\n';
	}

	return 0;
}
