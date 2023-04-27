#include <iostream>
#include <string>
#define MOD 1000000

using namespace std;

string n;
int cache[5001];
int nums[5001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int len = n.length();
	for (int i = 1; i <= len; i++) {
		nums[i] = n[i - 1] - '0';
	}

	if (nums[1] == 0) {
		cout << 0;
		return 0;
	}

	cache[0] = 1;
	for (int i = 1; i <= len; i++) {
		if (nums[i] >= 1 && nums[i] <= 9) {
			cache[i] = (cache[i] + cache[i - 1]) % MOD;
		}

		if (i == 1) continue;

		int tmp = nums[i - 1] * 10 + nums[i];
		if (tmp >= 10 && tmp <= 26) {
			cache[i] = (cache[i] + cache[i - 2]) % MOD;
		}
	}

	cout << cache[len] % MOD;

	return 0;
}