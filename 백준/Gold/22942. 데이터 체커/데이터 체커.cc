#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

vector<pii> v;
stack<pii> st;

bool compare(pii& a, pii& b) {
	return a.first < b.first;
}

int main() {
	int n;
	cin >> n;

	int x, radii;
	for (int i = 0; i < n; i++) {
		cin >> x >> radii;
		v.push_back({ x - radii, x + radii });
	}

	sort(v.begin(), v.end(), compare);

	bool flag = true;

	st.push(v[0]);
	for (int i = 1; i < v.size(); i++) {
		pii top = st.top();
		int topLeft = top.first;
		int topRight = top.second;

		int l = v[i].first;
		int r = v[i].second;

		if (topLeft < l && r < topRight) {
			st.push(v[i]);
		}
		else if (topRight < l) {
			st.pop();
			st.push(v[i]);
		}
		else {
			flag = false;
			break;
		}
	}

	cout << (flag ? "YES" : "NO");

	return 0;
}