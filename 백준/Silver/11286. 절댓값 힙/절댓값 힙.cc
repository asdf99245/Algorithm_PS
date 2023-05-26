#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct compare {
	bool operator()(int &a, int &b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}

		return abs(a) > abs(b);
	}
};

priority_queue<int, vector<int>, compare> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int x;
	while (n--) {
		cin >> x;

		if (x != 0) {
			pq.push(x);
		}
		else {
			if (pq.empty()) {
				cout << "0\n";
				continue;
			}
			cout << pq.top() << '\n';
			pq.pop();
		}
	}

	return 0;
}