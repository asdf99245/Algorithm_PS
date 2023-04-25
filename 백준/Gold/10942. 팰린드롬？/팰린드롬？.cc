#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int seq[2001];
int cache[2001][2001];

bool topDown(int s, int e) {
	if (s >= e) return 1;

	if (cache[s][e] != -1) return cache[s][e];

	cache[s][e] = 0;
	if (seq[s] != seq[e]) return cache[s][e];

	return cache[s][e] = topDown(s + 1, e - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &seq[i]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cache[i][j] = -1;
		}
	}

	for (int i = 1; i <= N; i++) {
		cache[i][i] = 1;
	}

	int s, e;

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &e);

		cout << topDown(s, e) << '\n';
	}

	return 0;
}