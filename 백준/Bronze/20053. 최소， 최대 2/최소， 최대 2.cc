#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		int mx = -1000001;
		int mn = 1000001;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			mx = max(mx, num);
			mn = min(mn, num);
		}

		cout << mn << ' ' << mx << '\n';
	}
	return 0;
}