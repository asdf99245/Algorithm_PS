#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct compare {
	bool operator()(int &a, int &b) {
		return a > b;
	}
};

priority_queue<int, vector<int>, compare> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	int num;
	for (int i = 0; i < n * n; i++) {
		cin >> num;

		if (pq.size() < n) {
			pq.push(num);
		}
		else if (pq.top() < num) {
			pq.pop();
			pq.push(num);
		}
	}

	cout << pq.top();

	return 0;
}