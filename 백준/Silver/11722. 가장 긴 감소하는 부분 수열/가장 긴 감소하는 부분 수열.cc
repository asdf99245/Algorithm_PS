#include <iostream>
#include <algorithm>
using namespace std;

int N;
int seq[1001];
int cache[1001];

int bottomUp() {
	int answer = cache[0];

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (seq[j] > seq[i]) {
				cache[i] = max(cache[i], cache[j] + 1);
			}
		}
		answer = max(answer, cache[i]);
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> seq[i];
	}

	fill(cache, cache + N, 1);

	cout << bottomUp();

	return 0;
}