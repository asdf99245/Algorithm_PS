#include <iostream>
#include <algorithm>

using namespace std;

int N;
int cache[1001];
int prices[1001];

int bottomUp() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			cache[i] = min(cache[i], cache[i - j] + prices[j]);
		}
	}

	return cache[N];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> prices[i];
		cache[i] = prices[i];
	}

	cout << bottomUp();

	return 0;
}