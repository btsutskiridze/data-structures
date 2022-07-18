#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& data) {
	for (int i = 1; i < data.size(); i++) {
		int value = data[i];
		int hole = i;
		while (hole > 0 && data[hole - 1] > value) {
			data[hole] = data[hole - 1];
			hole = hole - 1;
		}
		data[hole] = value;
	}
}
