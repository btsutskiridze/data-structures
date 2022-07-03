#include <iostream>
#include <string>


using namespace std;
//based on dynamic array
class Stack {
private:
	const static int max_cap = 100;
	int* arr;
	int top;	
public:
	Stack() {
		top = -1;
		arr = new int[max_cap];
	}
	
	~Stack(){
		delete[]arr;
	}
	Stack(Stack& other) {
		top = other.top;
		arr = new int[max_cap];
		for (int i = top; i >= 0; i--) {
			arr[i] = other.arr[i];
		}
	}

	Stack& operator=(Stack& other) {
		if (this != &other) {
			top = other.top;
			for (int i = top; i >= 0; i--) {
				arr[i] = other.arr[i];
			}
		}
		return *this;
	}

	bool isEmpty() {
		return top == -1;
	}
	void push(int val) {
		if (top < max_cap - 1) {
			++top;
			arr[top] = val;
		}
		else {
			cerr << "stack is full\n";
			exit(1);
		}
	}
	void display() {
		for (int i = top; i >= 0; i--) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void pop() {
		if (!isEmpty()) {
			top--;
		}
		else {
			cerr << "stack is empty\n";
			return;
		}
	}
	int Top() {
		if (!isEmpty()) {
			return arr[top];
		}
		else {
			cout << "stack is empty. returning garbage\n";
			int garbage; 
			return garbage;
		}
	}
};
