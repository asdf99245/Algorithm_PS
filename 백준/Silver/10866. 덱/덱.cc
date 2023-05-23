#include <iostream>
#include <string>
#define endl '\n';

using namespace std;

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* parent;
}Node;

class Deque {
private:
	Node* head = NULL;
	Node* tail = NULL;
	int sz = 0;
public:
	int size() {
		return sz;
	}
	int empty() {
		return sz == 0;
	}
	int front() {
		if (empty()) return -1;
		return head->data;
	}
	int back() {
		if (empty()) return -1;
		return tail->data;
	}
	void push_front(int x) {
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = x;
		node->parent = node->next = NULL;
		if (head == NULL) {
			head = node;
			tail = node;
		}
		else {
			node->next = head;
			head->parent = node;
			head = node;
		}
		sz++;
	}
	void push_back(int x) {
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = x;
		node->parent = node->next = NULL;
		if (tail == NULL) {
			head = node;
			tail = node;
		}
		else {
			node->parent = tail;
			tail->next = node;
			tail = node;

		}
		sz++;
	}
	int pop_front() {
		if (empty()) return -1;

		int x = front();
		Node* del = head;
		if (head->next != NULL) {
			head = head->next;
			head->parent = NULL;
			free(del);
			del = NULL;
		}
		else {
			free(del);
			head = NULL;
			tail = NULL;
		}
		sz--;
		return x;
	}
	int pop_back() {
		if (empty()) return -1;

		int x = back();
		Node* del = tail;
		if (tail->parent != NULL) {
			tail = tail->parent;
			tail->next = NULL;
			free(del);
			del = NULL;
		}
		else {
			free(del);
			head = NULL;
			tail = NULL;
		}
		sz--;
		return x;
	}

};

int main() {
	int n;
	cin >> n;

	string command;
	Deque dq;
	int num;
	while (n--) {
		cin >> command;

		if (command == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		else if (command == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		else if (command == "pop_front") {
			cout << dq.pop_front() << endl;
		}
		else if (command == "pop_back") {
			cout << dq.pop_back() << endl;
		}
		else if (command == "size") {
			cout << dq.size() << endl;
		}
		else if (command == "empty") {
			cout << dq.empty() << endl;
		}
		else if (command == "front") {
			cout << dq.front() << endl;
		}
		else if (command == "back") {
			cout << dq.back() << endl;
		}
	}

	return 0;
}