#include <iostream>
using namespace std;


class CircularQueue {
private:
	class Node {
	public:
		int val;
		Node* next;
		Node(int v = 0, Node* n = 0) :val(v), next(n) {}
	};
public:

	Node* front;
	Node* back;
	int size;

	CircularQueue() {
		front = NULL;
		back = NULL;
		size = 0;
	}

	CircularQueue(const CircularQueue& other) {
		front = NULL;
		back = NULL;
		if (!other.empty()) {
			//same as: front = back = new Node(other.front->val);
			front = new Node(other.Front());
			back = front;
			size = other.size;
			Node* origNextPtr = other.front->next;
			while (origNextPtr->next!= other.front) {
				back->next = new Node(origNextPtr->val);
				back = back->next;
				origNextPtr = origNextPtr->next;
			}
			//adding last
			back->next = new Node(origNextPtr->val);
			back = back->next;
			back->next = front;

		}
	}
	CircularQueue& operator=(const CircularQueue& other) {
		if (this != &other) {
			this->~CircularQueue();
			front = NULL;
			back = NULL;
			if (!other.empty()) {
				//same as: front = back = new Node(other.front->val);
				front = back = new Node(other.front->val);
				size = other.size;
				Node* origNextPtr = other.front->next;
				while (origNextPtr->next != other.front) {
					cout << origNextPtr->next << " ";
					back->next = new Node(origNextPtr->val);
					back = back->next;
					origNextPtr = origNextPtr->next;
				}
				//adding last
				back->next = new Node(origNextPtr->val);
				back = back->next;
				back->next = front;

			}
		}
		return *this;
	}

	~CircularQueue() {

		if (front) {
			Node* ptr = back;
			while (ptr != front)
			{
				ptr->next = front->next;
				delete front;
				front = ptr->next;
			}
			if (ptr == front) {
				delete front;
				front = nullptr;
			}
		}

	}

	bool empty() const {
		return size == 0;
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
			back->next = front;
		}
		size++;

	}

	void dequeue() {
		if (!empty()) {
			if (front == back) {
				delete front;
				front = back = NULL;
			}
			else {
				Node* temp = front;
				front = front->next;
				delete temp;
				back->next = front;
			}
			size--;
		}
		else {
			cerr << "QUEUE is empty\n";
		}
	}

	void display() {
		if (!empty()) {
			Node* temp = front;
 			while (temp->next != front) {
				cout << temp->val << " ";
				temp = temp->next;
			}
			cout << temp->val << " "; //then outputting last element
			cout << endl;
		}
		else {
			cerr << "QUEUE is empty\n";
		}
	}

	int Front() const {
		return front->val;
	}

};
