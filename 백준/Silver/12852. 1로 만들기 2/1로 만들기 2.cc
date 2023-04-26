#include <iostream>
#include <algorithm>

using namespace std;

int N;
int cache[1000001];
int trace[1000001];

int bottomUp(int n) {
	cache[1] = 0;

	for (int i = 2; i <= n; i++) {
		cache[i] = cache[i - 1] + 1;
		trace[i] = i - 1;

		if (i % 2 == 0) {
			if (cache[i] > cache[i / 2] + 1) {
				cache[i] = cache[i / 2] + 1;
				trace[i] = i / 2;
			}
		}

		if (i % 3 == 0) {
			if (cache[i] > cache[i / 3] + 1) {
				cache[i] = cache[i / 3] + 1;
				trace[i] = i / 3;
			}
		}
	}

	return cache[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	scanf("%d", &N);

	printf("%d\n", bottomUp(N));

	printf("%d ", N);
	int curr = N;
	while (trace[curr]) {
		printf("%d ", trace[curr]);
		curr = trace[curr];
	}

	return 0;
}