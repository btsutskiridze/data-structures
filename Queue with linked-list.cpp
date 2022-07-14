#include <iostream>
using namespace std;


class Queue {
private:
	class Node {
	public:
		int val;
		Node* next;
		Node(int v = 0, Node* n = 0) :val(v), next(n) {}
	};
	Node* front;
	Node* back;

public:
	Queue() {
		front = back = nullptr;
	}

	Queue(const Queue& other) {
		front = back = nullptr;
		if (!other.empty()) {
			front = back = new Node(other.front->val);
			Node* origFrontNext = other.front->next;
			while (origFrontNext!= 0) {
				back->next = new Node(origFrontNext->val);
				back = back->next;
				origFrontNext = origFrontNext->next;
			}
		}
	}
	Queue& operator=(const Queue& other) {
		if (this != &other) {
			this->~Queue();
			front = back = nullptr;
			if (!other.empty()) {
				front = back = new Node(other.front->val);
				Node* origPtrNext = other.front->next;
				while (origPtrNext != 0) {
					back->next = new Node(origPtrNext->val);
					back = back->next;
					origPtrNext = origPtrNext->next;
				}

			}
		}
		return *this;
	}

	~Queue() {
		Node* prev = front;
		Node* ptr;
		while (prev != 0) {
			ptr = prev->next;
			delete prev;
			prev = ptr;
		}
	}

	bool empty() const {
		return front == nullptr;
	}

	void enqueue(const int & val)
	{
		Node* newNode = new Node(val);
		if (empty()) {
			front = back = newNode;
		}
		else {
			back->next = newNode;
			back = newNode;
		}
	}

	void dequeue() {
		if (!empty()) {
			Node* temp= front;
			front = front->next;
			delete temp;
			if (front == 0) {
				back = 0;
			}
		}
		else {
			cerr << "QUEUE is empty\n";
		}
	}

	void display() {
		Node* temp = front;
		while(temp != 0) {
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	int Front() {
		return front->val;
	}

};
