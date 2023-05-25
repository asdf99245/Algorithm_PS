#include <iostream>
#include <stack>
#include <string>

using namespace std;

typedef struct StackItem {
	char c;
	int cnt = 0;
}StackItem;

int main() {
	string s;
	cin >> s;
	//()(((()())(())()))(())
	int ans = 0;
	stack<StackItem> st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			StackItem item;
			item.c = s[i];
			st.push(item);
		}
		else {
			if (st.top().c == '(') {
				if (st.top().cnt == 0) st.top().cnt = 1;
				else ans += st.top().cnt + 1;
				int count = st.top().cnt;
				st.pop();
				if(!st.empty()) st.top().cnt += count;
			}
			else {
				StackItem item;
				item.c = s[i];
				st.push(item);
			}
		}
	}

	cout << ans;

	return 0;
}