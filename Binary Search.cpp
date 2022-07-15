#include <iostream>

using namespace std;

bool binarySearch(int arr[],int number, int start, int end) {

	while (start <= end) {
		int middle = (start + end) / 2;

		if (arr[middle] == number) {
			return true;
		}
		else if (arr[middle] < number) {
			start = middle + 1;
		}
		else {
			end = middle - 1;
		}
	}

	return false;
}


int main()
{				//  0 1 2 3 4  5  6  7  8  9  10 11 12 13 14
	int arr[15] = { 1,3,4,7,12,21,25,37,42,49,51,53,57,64,65 };

	cout << boolalpha << binarySearch(arr,49,0,14) << endl;

	return 0;
}
