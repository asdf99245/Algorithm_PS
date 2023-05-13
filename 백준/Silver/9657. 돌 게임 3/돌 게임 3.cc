#include <iostream>

using namespace std;

int N;
int cache[1001];

void bottomUp() {
	cache[1] = 0;
	cache[2] = 1;
	cache[3] = 0;
	cache[4] = 0;

	for (int i = 5; i <= N; i++) {
		cache[i] = !(cache[i - 1] || cache[i - 3] || cache[i - 4]);
	}
}

int main() {
	cin >> N;

	bottomUp();

	cout << (cache[N] ? "CY" : "SK");

	return 0;
}