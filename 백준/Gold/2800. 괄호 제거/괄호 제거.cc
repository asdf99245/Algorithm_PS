#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <set>

using namespace std;

typedef pair<int, int> pii;

typedef struct StackItem {
	char c;
	int idx;
}StackItem;

vector<pii> v;
set<string> ans;

void dfs(int idx, vector<pii> pairs, string input) {
	if (idx >= v.size()) {
		if (pairs.size() == 0) return;

		set<int> skips;

		for (auto p : pairs) {
			skips.insert(p.first);
			skips.insert(p.second);
		}

		string temp = "";
		for (int i = 0; i < input.length(); i++) {
			if (skips.find(i) != skips.end()) continue;
			temp += input[i];
		}
		ans.insert(temp);
		return;
	}

	dfs(idx + 1, pairs, input);
	pairs.push_back(v[idx]);
	dfs(idx + 1, pairs, input);
}

int main() {
	stack<StackItem> st;

	string input;
	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(') {
			StackItem item;
			item.c = input[i];
			item.idx = i;
			st.push(item);
		}
		else if(input[i] == ')' && st.top().c == '('){
			v.push_back({ st.top().idx, i });
			st.pop();
		}
	}

	vector<pii> pairs;
	dfs(0, pairs, input);

	for (auto iter = ans.begin(); iter != ans.end(); iter++) {
		cout << *iter << '\n';
	}

	return 0;
}