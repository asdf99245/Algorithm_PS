#include <iostream>
#include <queue>

using namespace std;

void step(queue<int>& q) {
	q.pop();

	int x = q.front();
	q.pop();
	q.push(x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	queue<int> q;

	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}

	while (q.size() > 1) {
		step(q);
	}

	cout << q.front();

	return 0;
}