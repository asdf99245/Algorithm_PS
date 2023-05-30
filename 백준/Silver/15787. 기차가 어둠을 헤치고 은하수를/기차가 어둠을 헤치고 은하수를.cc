#include <iostream>
#include <deque>
#include <unordered_set>

using namespace std;

int train[100001];

int n, m;
int main() {
	cin >> n >> m;

	while (m--) {
		int command, x, i;
		cin >> command;

		switch (command) {
			case 1:
				cin >> i >> x;
				train[i] |= 1 << (x - 1);
				break;
			case 2:
				cin >> i >> x;
				train[i] &= ~(1 << (x - 1));
				break;
			case 3:
				cin >> i;

				train[i] = train[i] << 1;
				train[i] &= ~(1 << 20);
				break;
			case 4:
				cin >> i;

				train[i] = train[i] >> 1;
				break;
			default:
				break;
		}
	}

	unordered_set<int> _set;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (_set.find(train[i]) != _set.end()) continue;
		_set.insert(train[i]);
		cnt++;
	}

	cout << cnt;

	return 0;
}