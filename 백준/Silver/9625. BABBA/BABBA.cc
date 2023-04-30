#include <iostream>
#include <algorithm>

using namespace std;

int K;
int cache[2][46];

void bottomUp() {
	cache[0][0] = 1; 
	cache[1][0] = 0;
	for (int i = 1; i <= K; i++) {
		cache[0][i] = cache[1][i - 1];
		cache[1][i] = cache[0][i - 1] + cache[1][i - 1];
	}

	cout << cache[0][K] << ' ' << cache[1][K];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> K;

	bottomUp();

	return 0;
}