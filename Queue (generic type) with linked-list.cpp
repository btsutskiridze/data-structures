#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
	class Node {
	public:
		T val;
		Node* next;
		Node(T v, Node* n = NULL) {
			val = v;
			next = n;
		}


	};
	Node* head;
	Node* tail;
	int Size;

public:
	Queue();

	~Queue();

	Queue(const Queue& other);

	const Queue& operator=(const Queue& other);

	bool empty() const;

	void enqueue(const T &val);

	T dequeue();

	T peek() const;

	T Tail() const;

	void display(ostream& out) const;

};


template<typename T>
inline Queue<T>::Queue()
{
	head = tail = NULL;
	Size = 0;
}

template<typename T>
inline Queue<T>::~Queue()
{
	Node* prev = head;
	Node* ptr;
	while (prev != 0) {
		ptr = prev->next;
		delete prev;
		prev = ptr;
	}
}

template<typename T>
inline Queue<T>::Queue(const Queue& other)
{
	head = tail = NULL;
	if(!other.empty()){
		head = tail = new Node(other.peek());
		Node* otherPtr = other.head->next;
		while (otherPtr != 0) {
			tail->next = new Node(otherPtr->val);
			tail = tail->next;
			otherPtr = otherPtr->next;
		}
	}
	Size = other.Size;
}

template<typename T>
inline const Queue<T>& Queue<T>::operator=(const Queue& other)
{
	if (this != &other) {
		this->~Queue();
		head = tail = NULL;
		if (!other.empty()) {
			head = tail = new Node(other.peek());
			Node* otherPtr = other.head->next;
			while (otherPtr != 0) {
				tail->next = new Node(otherPtr->val);
				tail = tail->next;
				otherPtr = otherPtr->next;
			}
		}
		Size = other.Size;
	}
	return *this;
}

template<typename T>
inline bool Queue<T>::empty() const {
	return Size == 0;
}


template <typename T>
inline void Queue<T>::enqueue(const T &val){
	Node* newNode = new Node(val);
	if (empty()) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	Size++;
}

template <typename T>
inline T Queue<T>::dequeue() {
	if (!empty()) {
		T value = head->val;
		Node* temp = head;
		head = head->next;
		delete temp;

		if (head == NULL) {
			tail = NULL;
		}
		Size--;
		return value;
	}
	else {
		cerr << "Queue is empty. Cannot dequeue\n";
		T* temp = new (T);
		T garbage = *temp;
		delete temp;
		return garbage;
	}
}

template<typename T>
inline T Queue<T>::peek() const
{
	if (!empty()) {
		return head->val;
	}
	else {
		cout << "Queue is empty. returning garbage\n";
		T *temp = new (T);
		T garbage = *temp;
		delete temp;
		return garbage;
	}
}

template<typename T>
T Queue<T>::Tail() const {
	if (!empty()) {
		return tail->val;
	}
	else {
		cout << "Queue is empty. returning a garbage\n";
		T* temp = new (T);
		T garbage = *temp;
		delete temp;
		return garbage;
	}
}



template <typename T>
inline void Queue<T>::display(ostream& out) const {
	Node* temp = head;
	while (temp != 0) {
		out << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}
