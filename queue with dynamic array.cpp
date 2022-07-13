#include <iostream>
using namespace std;

int CAP = 100;

class Queue {
private:
	int front;
	int back;
	int* arr;
public:
	Queue() {
		front = 0;
		back = 0;
		arr = new int[CAP];

	}
	Queue(const Queue& other) {
		arr = new int[CAP];
		if (!other.empty()){
			front = other.front;
			back = other.back;
			for (int i = front; i != back; i++) {
				arr[i] = other.arr[i];
			}
		}
		else {
			front = back = 0;
		}
	
	}
	Queue& operator=(const Queue& other) {
		if (this != &other) {
			Queue::~Queue();
			arr = new int[CAP];
			if (!other.empty()) {
				front = other.front;
				back = other.back;
				for (int i = front; i != back; i++) {
					arr[i] = other.arr[i];
				}
			}
			else {
				front = 0;
				back = 0;
			}

		}
		return *this;
	}

	~Queue() {
		delete[]arr;
	}

	bool empty() const {
		return front == back;
	}

	bool Full()const {
		return back == CAP - 1;
	}

	void enqueue(const int & val)
	{
		if (Full()) {
			cerr << "queue is full\n";
		}
		else {
			arr[back++] = val;
		}
	}

	void dequeue() {
		if (empty()) {
			cerr << "cannot dequeue\n";
		}
		else {
			front = front + 1;
		}
	}

	void display() {
		for (int i = front; i != back; i++) {
			cout << arr[i] << ' ';
		}
		cout << endl;
	}


};
