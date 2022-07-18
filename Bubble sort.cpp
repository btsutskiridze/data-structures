#include <cstring>
#include <vector>

using namespace std;

void bubbleSort(vector<int>&data) {
	for (int step = 0; step < data.size() -1; step++) {
		int swapped = 0;
		for (int j = 0; j < data.size() - step - 1; j++) {
			if (data[j] > data[j + 1]) {
				swap(data[j], data[j + 1]);
				swapped = 1;
				cout << "\nswapped\n";
			}
		}

		if (swapped == 0)
			break;

	}
}
