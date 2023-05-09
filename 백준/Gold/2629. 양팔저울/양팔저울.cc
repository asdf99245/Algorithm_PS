#include <iostream>
#include <cmath>

using namespace std;

int N, M;
int weights[31];
int marbles[8];

bool cache[31][30 * 500 + 1];

void dp(int cnt, int acc) {
	if (cnt > N || cache[cnt][acc]) return;

	cache[cnt][acc] = true;

	dp(cnt + 1, acc + weights[cnt]);
	dp(cnt + 1, acc);
	dp(cnt + 1, abs(acc - weights[cnt]));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> weights[i];
	}

	dp(0, 0);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> marbles[i];

		if (marbles[i] > 30 * 500) cout << "N ";
		else cout << (cache[N][marbles[i]] ? "Y " : "N ");
	}


	return 0;
}