#include <iostream>
#include <stack>

using namespace std;

int tops[500001];
int ans[500001];

typedef pair<int, int> pii;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tops[i];
	}

	stack<pii> st;
	for (int i = n - 1; i >= 0; i--) {
		if (st.empty()) {
			st.push({ tops[i], i });
			continue;
		}

		while (!st.empty() && tops[i] >= st.top().first) {
			ans[st.top().second] = i + 1;
			st.pop();
		}

		st.push({ tops[i], i });
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}

	return 0;
}