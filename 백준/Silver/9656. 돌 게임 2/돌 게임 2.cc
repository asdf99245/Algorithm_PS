#include <iostream>
#include <algorithm>

using namespace std;

int N;
int cache[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	cache[1] = 0;
	cache[2] = 1;
	cache[3] = 0;
	for (int i = 4; i <= N; i++) {
		if (cache[i - 1] == 0 && cache[i - 3] == 0) cache[i] = 1;
		else cache[i] = 0;
	}

	cout << (cache[N] == 0 ? "CY" : "SK");

	return 0;
}