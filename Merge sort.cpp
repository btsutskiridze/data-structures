#include <iostream>

using namespace std;

// Function to Merge Arrays L and R into A. 
// lefCount = number of elements in L
// rightCount = number of elements in R. 
void Merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
	int i, j, k;

	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	i = 0; j = 0; k = 0;

	while (i < leftSize && j < rightSize) {
		if (left[i] <= right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}

	while (i < leftSize)
		arr[k++] = left[i++];
	while (j < rightSize)
		arr[k++] = right[j++];
}

void mergeSort(int arr[], int size) {

	if (size < 2) // base condition. If the array has less than two element, do nothing. 
		return; 

	int mid = size / 2; // find the mid index.

	// create left and right subarrays
	// mid elements (from index 0 till mid-1) should be part of left sub-array 
	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
	int *left = new int[mid];
	int *right = new int[size - mid];

	for (int i = 0; i < mid; i++)
		left[i] = arr[i]; // creating left subarray
	for (int i = mid; i < size; i++)
		right[i - mid] = arr[i]; // creating right subarray
	 
	mergeSort(left, mid); // sorting the left subarray
	mergeSort(right, size - mid); // sorting the right subarray
	Merge(arr, left, mid, right, size - mid); // Merging Left and Right into Array as sorted list.

  //deallocating memory
	delete[]left; 
	delete[]right; 
}

int main()
{				
	int data[] = {-2, 45, 0, 11, -9};
	
	mergeSort(data, 5);


	for (int i = 0; i < 5; i++) {
		cout << data[i] << " ";
	}

	return 0;
}


