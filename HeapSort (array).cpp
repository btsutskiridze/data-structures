#include <iostream>

using namespace std;


void heapify(int arr[], int size, int i) {
	int largest = i;
	int leftIndex = 2 * i + 1;
	int rightIndex = 2 * i + 2;

	if (leftIndex < size && arr[leftIndex] > arr[largest]) {
		largest = leftIndex;
	}

	if (rightIndex < size && arr[rightIndex]> arr[largest]) {
		largest = rightIndex;
	}

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, size, largest);
	}
}

void heapSort(int arr[], int n) {

	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}




int main()
{				
	int data[] = {-2, 45, 0, 11, -9};


	heapSort(data, 5);

	for (int i = 0; i < 5; i++) {
		cout << data[i] << " ";
	}
	cout << endl;


	return 0;
}
