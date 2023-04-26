#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;

int n;
int cache[50001];

void bottomUp() {
	fill(cache, cache + n + 1, INF);

	cache[0] = 0;
	cache[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			cache[i] = min(cache[i], cache[i - j * j] + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	scanf("%d", &n);

	bottomUp();

	printf("%d", cache[n]);

	return 0;
}