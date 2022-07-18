#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& data) {
	int MIN_index;
	for (int i = 0; i < data.size() - 1; i++) {
		MIN_index = i;
		for (int j = i + 1; j < data.size(); j++) {
			if (data[MIN_index]> data[j]) {
				MIN_index = j;
			}
		}
		swap(data[MIN_index], data[i]);
	}
}
