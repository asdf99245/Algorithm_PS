#include <iostream>
#include <algorithm>
#define MAX 100000

using namespace std;

int cache[MAX + 1][2];
int seq[MAX + 1];

void bottomUp(int n) {
	cache[0][0] = seq[0];
	cache[0][1] = seq[0];
	int ret = max(cache[0][1], cache[0][0]);
	for (int i = 1; i < n; i++) {
		cache[i][0] = max(cache[i - 1][0] + seq[i], seq[i]);
		cache[i][1] = max(cache[i - 1][0], cache[i - 1][1] + seq[i]);

		ret = max(ret, max(cache[i][0], cache[i][1]));
	}

	cout << ret;
}

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}

	bottomUp(n);

	return 0;
}