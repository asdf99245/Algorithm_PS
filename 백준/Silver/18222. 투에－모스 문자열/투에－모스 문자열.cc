#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
ll k;

ll solve(ll n) {
	if (n == 0) return 0;

	ll num = 1;

	while (num + num <= n) {
		num += num;
	}

	return !solve(n - num);
}

int main() {
	cin >> k;

	cout << solve(k - 1);

	return 0;
}