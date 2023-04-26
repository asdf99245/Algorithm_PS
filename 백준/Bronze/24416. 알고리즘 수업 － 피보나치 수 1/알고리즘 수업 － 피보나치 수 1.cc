#include <iostream>

using namespace std;

int cache[41];
int cnt1 = 0, cnt2 = 0;

int fib(int n) {
	if (n == 1 || n == 2) {
		cnt1++;
		return 1;
	}

	return fib(n - 1) + fib(n - 2);
}

int fibDP(int n) {
	cache[1] = cache[2] = 1;

	for (int i = 3; i <= n; i++) {
		cache[i] = cache[i - 1] + cache[i - 2];
		cnt2++;
	}

	return cache[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;

	scanf("%d", &n);

	fib(n);
	fibDP(n);

	printf("%d %d", cnt1, cnt2);

	return 0;
}