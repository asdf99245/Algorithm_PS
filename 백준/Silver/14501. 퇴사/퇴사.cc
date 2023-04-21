#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int time[16];
int profit[16];

int cache[16];

int main() {
	int N;
	cin >> N;

	memset(cache, 0, sizeof(cache));
	for (int i = 0; i < N; i++) {
		cin >> time[i] >> profit[i];
	}

	int max_v = 0;
	for (int i = 0; i <= N; i++) {
		cache[i] = max(max_v, cache[i]);
		if (time[i] + i <= N) {
			cache[time[i] + i] = max(cache[time[i] + i], profit[i] + cache[i]);
		}
		max_v = max(max_v, cache[i]);
	}

	cout << cache[N];

	return 0;
}