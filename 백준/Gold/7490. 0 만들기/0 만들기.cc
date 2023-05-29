#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<string> v;

int calc(string s) {
	int sum = 0;

	string buffer = "";

	queue<string> q;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') continue;

		if (s[i] == '+' || s[i] == '-') {
			q.push(buffer);
			buffer = "";
		}

		if (s[i] == '+') {
			q.push("+");
		}
		else if (s[i] == '-') {
			q.push("-");
		}
		else {
			buffer += s[i];
		}
	}

	if (buffer.length() > 0) q.push(buffer);

	sum += stoi(q.front());
	q.pop();

	while (!q.empty()) {
		string fr = q.front();
		q.pop();

		if (fr == "+") {
			sum += stoi(q.front());
			q.pop();
		}
		else if (fr == "-") {
			sum -= stoi(q.front());
			q.pop();
		}
	}

	return sum;
}

void dfs(int curr, string acc, int n) {
	if (curr == n) {
		if (calc(acc) == 0) {
			v.push_back(acc);
		}
		return;
	}

	int next = curr + 1;
	dfs(next, acc + "+" + to_string(next), n);
	dfs(next, acc + "-" + to_string(next), n);
	dfs(next, acc + " " + to_string(next), n);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		dfs(1, "1", n);

		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << '\n';
		}
		v.clear();

		if(t > 0) cout << '\n';
	}

	return 0;
}