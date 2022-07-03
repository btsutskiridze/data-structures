#include <iostream>
#include <string>

using namespace std;
//based on linked-list
class Stack {
private:
	class Node {
	public:
		int data;
		Node* next;
		Node(int Data = 0, Node* Next = 0) :data(Data), next(Next) {
		}
	};
	Node* top;
public:

	Stack() {
		top = 0;
	}

	~Stack() {
		Node* current = top;
		Node* next;

		while (current != 0) {
			next = current->next;
			delete current;
			current = next;
		}
	}
	
	Stack(Stack& other) {
		top = new Node(other.Top());
		Node* ptrToOther = other.top->next, *ptrToOwnTop = top;
		while (ptrToOther != 0) {
			ptrToOwnTop->next =new Node(ptrToOther->data);
			ptrToOther = ptrToOther->next;
			ptrToOwnTop = ptrToOwnTop->next;
		}

	}

	Stack& operator=(Stack& other) {
		if (this != &other) {
			this->~Stack();
			if (other.empty()) {
				top = 0;
			}
			else {
				top = new Node(other.Top());
				Node* ptrToOther = other.top->next;
				Node* ptrToOwnTop = top;
				while (ptrToOther != 0) {
					ptrToOwnTop->next = new Node(ptrToOther->data);
					ptrToOwnTop = ptrToOwnTop->next;
					ptrToOther = ptrToOther->next;
				}
			}
		}
		return *this;
	}

	void push(int val) {
		top = new Node(val, top);
	}

	void pop() {
		Node* temp = top;
		top = top->next;
		delete temp;
	}

	void display() {
		Node* temp = top;
		while (temp != 0) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	int Top() {
		return top->data;
	}

	bool empty() {
		return top == 0;
	}

};