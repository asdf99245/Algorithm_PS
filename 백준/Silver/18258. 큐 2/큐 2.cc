#include <iostream>
#include <deque>
#include <string>
#define endl '\n';
using namespace std;

class Queue {
private:
	deque<int> dq;
public:
	bool isEmpty() {
		return dq.empty();
	}
	int size() {
		return dq.size();
	}
	int front() {
		if (isEmpty()) return -1;
		return dq.front();
	}
	int back() {
		if (isEmpty()) return -1;
		return dq.back();
	}
	void push(int x) {
		dq.push_back(x);
	}
	int pop() {
		if (isEmpty()) return -1;
		int x = front();
		dq.pop_front();
		return x;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	Queue myqueue;
	string command;
	while (n--) {
		cin >> command;
		if (command == "push") {
			int num;
			cin >> num;
			myqueue.push(num);
		}
		else if (command == "pop") {
			cout << myqueue.pop() << endl;
		}
		else if (command == "front") {
			cout << myqueue.front() << endl;
		}
		else if (command == "back") {
			cout << myqueue.back() << endl;
		}
		else if (command == "size") {
			cout << myqueue.size() << endl;
		}
		else if (command == "empty") {
			cout << myqueue.isEmpty() << endl;
		}
	}
	return 0;
}