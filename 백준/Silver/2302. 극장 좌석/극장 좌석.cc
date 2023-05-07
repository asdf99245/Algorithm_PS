#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int vips[41];
int cache[41];

void bottomUp() {
	cache[0] = 1;
	cache[1] = 1;
	cache[2] = 2;
	
	for (int i = 3; i <= N; i++) {
		cache[i] = cache[i - 1] + cache[i - 2];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> vips[i];
	}

	bottomUp();

	int cnt = 0;
	int start = 1;
	int answer = 1;
	for (int i = 0; i < M; i++) {
		int e = vips[i];
		answer *= cache[e - start];

		start = e + 1;
	}
	answer *= cache[N - start + 1];

	cout << answer;

	return 0;
}