#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

int cache[501][501];
vector<int> v[501];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			int num;
			cin >> num;
			v[i].push_back(num);
		}
	}

	memset(cache, -1, sizeof(cache));

	cache[1][0] = v[1][0];
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 0; j < i; j++) {
			cache[i + 1][j] = max(cache[i + 1][j], cache[i][j] + v[i + 1][j]);
			cache[i + 1][j + 1] = max(cache[i + 1][j + 1], cache[i][j] + v[i + 1][j + 1]);
		}
	}

	int answer = cache[N][0];
	for (int i = 1; i < v[N].size(); i++) answer = max(answer, cache[N][i]);
	cout << answer;
	return 0;
}