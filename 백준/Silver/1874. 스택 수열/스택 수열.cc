#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int seq[100001];
vector<char> opers;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> seq[i];
	}

	stack<int> st;
	int cnt = 1;

	/*
	4
	3
	6
	8
	7
	5
	2
	1
	*/
	for (int i = 1; i <= n; i++) {
		int num = seq[i];

		if (!st.empty()) {
			while (st.top() != num && cnt <= n) {
				st.push(cnt++);
				opers.push_back('+');
			}

			if (st.top() == num) {
				st.pop();
				opers.push_back('-');
			}
			else {
				break;
			}
		}
		else {
			while (cnt <= n) {
				st.push(cnt++);
				opers.push_back('+');
				if (st.top() == num) break;
			}

			if (st.top() == num) {
				st.pop();
				opers.push_back('-');
			}
			else {
				break;
			}
		}
	}

	if (!st.empty()) {
		cout << "NO";
		return 0;
	}

	for (int i = 0; i < opers.size(); i++) {
		cout << opers[i] << '\n';
	}

	return 0;
}