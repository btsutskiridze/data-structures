#include <iostream>
#include <string>


using namespace std;

class DynamicList {
private:
	int size;
	int CAP;
	int* arr;

public:
	DynamicList(int cap = 1024) {
		size = 0;
		CAP = cap;
		arr = new int[CAP];
	}
	DynamicList(DynamicList& other) {
		size = other.size;
		CAP = other.CAP;
		arr = new int[CAP];
		for (int i = 0; i < size; i++) {
			arr[i] = other.arr[i];
		}
	}
	~DynamicList() {
		delete[]arr;
	}
	void insert(int val) {
		if (isFull()) {
			cerr << "array is full\n";
		}
		else {
			arr[size++] = val;
		}
	}
	void insertAt(int val, int pos) {
		if (isFull()) {
			cerr << "array is full\n";
			return;
		}
		else if (pos > size) {
			cerr << "wrong position\n";
			return;
		}
		else {
			for (int i = size; i >= pos; i--) {
				arr[i + 1] = arr[i];
			}
			arr[pos] = val;
			size++;
		}
	}
	bool isFull() {	
		return size == CAP;
	
	}
	void display() {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void deleteAt(int pos) {
		if (size == 0) {
			cerr << "array is empty\n";
			return;
		}
		else if (pos >= size || pos < 0) {
			cerr << "wrong position\n";
			return;
		}
		else {
			for (int i = pos; i < size; i++) {
				arr[i] = arr[i+1];
			}
			size--;
		}
	}

	DynamicList& operator=(DynamicList& other) {
		if (this != &other) {
			if (CAP != other.CAP) {
				delete[]arr;
				CAP = other.CAP;
				arr = new (nothrow) int[CAP];
				if (arr == 0) {
					cerr << "allocation fail\n";
					exit(1);
				}
			}
			size = other.size;
			for (int i = 0; i < size; i++) {
				arr[i] = other.arr[i];
			}
		}
		return *this;
	}


};
