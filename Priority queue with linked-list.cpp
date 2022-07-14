#include <iostream>
using namespace std;


class PriorityQueue {
private:
	class Node {
	public:
		int val;
		int priority;
		Node* next;
		Node(int v = 0, int p = 0, Node* n = 0) :val(v), priority(p), next(n) {}
	};
	Node* head;
public:
	PriorityQueue() {
		head = nullptr;
	}
	PriorityQueue(const PriorityQueue& other) {
		//not implemented
	}
	PriorityQueue& operator=(const PriorityQueue& other) {
		//not implemented
	}
	void push(int val, int p) {
		// Create a new node
		Node* newNode = new Node(val, p);

		// If head is null, this is the first node to be added
		// so make head = newNode
		if (head == nullptr) {
			head = newNode;
			return;
		}
		Node* temp = head;
		Node* prev = nullptr;
		
		// search for first node having priority less than p
		while (temp != 0 && temp->priority > p) {
			prev = temp;
			temp = temp->next;
		}


		if (temp == 0) {
			// no node with priority less than this node (Case 1)
			prev->next = newNode;
		}
		else {
			if (prev == 0) {
				// all the nodes have priority less than p (Case 2)
				// add this node at the starting
				newNode->next = head;
				head = newNode;
			}
			else {
				// Case 3
				// add this node before the node with priority less than p
				newNode->next = temp;
				prev->next = newNode;
			}
		}
	}


	int pop() {
		// head of the linked list contains the maximum priority element
		if (head != NULL) {
			int data = head->val;
			Node* temp = head;
			head = head->next;
			delete temp;
			return data;
		}
		return -1;
	}

	int peek() {
		// head of the linked list contains the maximum priority element
		if (head != NULL) {
			return head->val;
		}
		return -1;
	}

	void display() {
		Node* temp = head;
		while (temp != 0) {
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;


	}
};
