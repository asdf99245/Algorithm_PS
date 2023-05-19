#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> ans;
	deque<int> dq;
	for (int i = 0; i < N; i++) {
		dq.push_back(i + 1);
	}

	int cnt = 0;
	while (!dq.empty()) {
		if (++cnt == K) {
			ans.push_back(dq.front());
			dq.pop_front();
			cnt = 0;
			continue;
		}

		int front = dq.front();
		dq.pop_front();
		dq.push_back(front);
	}

	cout << '<';
	for (int i = 0; i < N - 1; i++) {
		cout << ans[i] << ", ";
	}
	cout << ans[N - 1] << '>';
	return 0;
}