#include <iostream>
#include <vector>
#include <limits>
using namespace std;

void merge(vector<int>& leftArray, vector<int>& rightArray, vector<int>& arr);

void mergeSort(vector<int>& arr) {
	int length = arr.size();
	if (length <= 1) return;

	int leftLength = length / 2;
	int rightLength = length - leftLength;

	vector<int> leftArray(leftLength);
	vector<int> rightArray(rightLength);

	int i, j;
	i = j = 0;
	for (; i < length; i++) {
		if (i < leftLength) {
			leftArray[i] = arr[i];
		}
		else {
			rightArray[j] = arr[i];
			j++;
		}
	}

	mergeSort(leftArray);
	mergeSort(rightArray);
	merge(leftArray, rightArray, arr);

}

void merge(vector<int>& leftArray, vector<int>& rightArray, vector<int>& arr) {

	int leftSize = leftArray.size();
	int rightSize = rightArray.size();
	int i = 0, j = 0, k = 0;

	while (i < leftSize && j < rightSize) {
		if (leftArray[i] <= rightArray[j]) {
			arr[k] = leftArray[i];
			i++;
		}
		else {
			arr[k] = rightArray[j];
			j++;
		}
		k++;
	}

	while (i < leftSize) {
		arr[k] = leftArray[i];
		i++;
		k++;
	}

	while (j < rightSize) {
		arr[k] = rightArray[j];
		j++;
		k++;
	}

}

int besarMana(int& a, int& b) {
	return (a > b) ? a : b;
}

int palingBesar(vector<int>& arr) {
	int maks = numeric_limits<int>::min();

	for (int& i : arr) {
		maks = besarMana(maks, i);
	}

	return maks;
}


int main() {
	int panjangArray;
	cin >> panjangArray;
	vector<int> Array(panjangArray);

	for (int i = 0; i < panjangArray; i++) {
		cin >> Array[i];
	}

	cout << endl;

	cout << "Array sebelum diurutkan : " << endl;
	for (const int& i : Array) {
		cout << i << " ";
	}
	cout << endl;

	cout << "Nilai Maksimum          : " << palingBesar(Array) << endl;

	mergeSort(Array);

	cout << "Array setelah diurutkan : " << endl;
	for (const int& i : Array) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
