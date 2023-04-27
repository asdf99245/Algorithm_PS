#include <iostream>

using namespace std;

typedef long long ll;

int N;
int nums[101];
ll cache[101][21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	cache[0][nums[0]] = 1;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (cache[i - 1][j] > 0) {
				if (j - nums[i] >= 0) {
					cache[i][j - nums[i]] += cache[i - 1][j];
				}

				if (j + nums[i] <= 20) {
					cache[i][j + nums[i]] += cache[i - 1][j];
				}
			}
		}
	}

	cout << cache[N - 2][nums[N - 1]];

	return 0;
}