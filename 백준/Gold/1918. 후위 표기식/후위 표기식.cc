#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<string> v;
stack<char> st;

int main() {
	string input;
	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		char c = input[i];

		if (c >= 'A' && c <= 'Z') {
			cout << c;
		}
		else if (c == '(') {
			st.push(c);
		}
		else if (c == ')') {
			while (st.top() != '(') {
				cout << st.top();
				st.pop();
			}

			st.pop();
		}
		else {
			if (c == '+' || c == '-') {
				while (!st.empty() && st.top() != '(') {
					cout << st.top();
					st.pop();
				}
				st.push(c);
			}
			else {
				while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
					cout << st.top();
					st.pop();
				}
				st.push(c);
			}
		}
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}

	return 0;
}