#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

map<char, int> mp;

int main() {
	int n;
	cin >> n;

	string oper;
	stack<double> st;

	cin >> oper;

	char c = 'A';
	for (int i = 0; i < n; i++) {
		cin >> mp[c];
		c++;
	}

	double a, b;
	for (int i = 0; i < oper.length(); i++) {
		c = oper[i];
		if (c == '*') {
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();

			st.push(b * a);
		}
		else if (c == '/') {
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();

			st.push(b / a);
		}
		else if (c == '+') {
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();

			st.push(b + a);
		}
		else if (c == '-') {
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();

			st.push(b - a);

		}
		else {
			st.push(mp[c]);
		}
	}

	cout.precision(2);
	cout << fixed;
	cout << st.top();

	return 0;
}