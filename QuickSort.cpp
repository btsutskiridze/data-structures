#include <iostream>

using namespace std;

//partition
int partition(int arr[], int start, int end) {
	int pivot = arr[end];
	int partitionIndex = start; //set partition index as start initially
	for (int i = start; i < end; i++) 
		if (arr[i] <= pivot)
			swap(arr[i], arr[partitionIndex++]); //swap if element is lesser than pivot
	
	swap(arr[partitionIndex], arr[end]); //swap pivot with element at partition index
	return partitionIndex; //return partition index
}

//Quicksort 
void Quicksort(int arr[], int start, int end) {
	if (start < end) {

		int partitionIndex = partition(arr, start, end); //calling partition function
		Quicksort(arr, start, partitionIndex - 1); //recursion for left side
		Quicksort(arr, partitionIndex + 1, end); //recursion for right side

	}
}


int main()
{				
	int data[] = {-2, 45, 0, 11, -9};
	//							            pivot
	//							              |
	//							              V
	//			      -2, 45, 0, 11, -9
	//then->      -9, 45, 0, 11, -2 
	//then->	    -9, -2, 0, 11, 45

	Quicksort(data, 0,4);

	for (int i = 0; i < 5; i++) {
		cout << data[i] << " ";
	}
	cout << endl;


	return 0;
}
