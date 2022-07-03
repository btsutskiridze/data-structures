#include <iostream>
#include <string>


using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node(int Val = 0, Node *Next = 0) :val(Val), next(Next) {}
	
};

void push_back(int val, Node *head) {
	Node* temp = new Node(val);
	Node* ptr = head;
	while (ptr->next!= 0) {
		ptr = ptr->next;
	}
	ptr->next = temp;
}

void display(Node* head) {
	Node* temp = head;
	while (temp != 0) {
		cout << temp->val<<" ";
		temp = temp->next;
	}
}

void pop(Node* head) {
	Node* temp = head;
	while (temp->next->next != 0) {
		temp = temp->next;
	}
	temp->next = NULL;
}