#include <iostream>
#include <stack>

using namespace std;

int main() {
	int K;

	cin >> K;

	stack<int> st;
	int num;
	for (int i = 0; i < K; i++) {
		cin >> num;
		if (num == 0) st.pop();
		else st.push(num);
	}

	int sum = 0;
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}

	cout << sum;

	return 0;
}