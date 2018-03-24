/*
Student ID : 2013113504
Student Name : KIM JIN BEOM

Question 2. Heap Sort
Let's implement the heap sort. A = [4, 1, 3, 2, 16, 9, 10, 14, 8, 7]
Problem 1. heap construction
1)Draw the complete binary tree for each step (use the second algorithm learned at the lecture)
2)Implement thid and print the heap in code.

Problem 2. heap sort utilizing the heap
1)Draw the complete binary tree for each step (use the second algorithm learend at the lecture)
2)Implement this and print the sorted values int the code.

input :
10
4 1 3 2 16 9 10 14 8 7

output: 
BEFOR CONSTRUCT : [4, 1, 3, 2, 16, 9, 10, 14, 8, 7]
CONSTRUCTING >>
[4, 1, 3, 14, 16, 9, 10, 2, 8, 7]
[4, 1, 10, 14, 16, 9, 3, 2, 8, 7]
[4, 16, 10, 14, 1, 9, 3, 2, 8, 7]
[4, 16, 10, 14, 7, 9, 3, 2, 8, 1]
[16, 4, 10, 14, 7, 9, 3, 2, 8, 1]
[16, 14, 10, 4, 7, 9, 3, 2, 8, 1]
[16, 14, 10, 8, 7, 9, 3, 2, 4, 1]

BEFOR SORTING : [16, 14, 10, 8, 7, 9, 3, 2, 4, 1]
SORTING >>
SORTED ARRAY : [16]
[14, 1, 10, 8, 7, 9, 3, 2, 4]
[14, 8, 10, 1, 7, 9, 3, 2, 4]
[14, 8, 10, 4, 7, 9, 3, 2, 1]
SORTED ARRAY : [16, 14]
[10, 8, 1, 4, 7, 9, 3, 2]
[10, 8, 9, 4, 7, 1, 3, 2]
SORTED ARRAY : [16, 14, 10]
[9, 8, 2, 4, 7, 1, 3]
[9, 8, 3, 4, 7, 1, 2]
SORTED ARRAY : [16, 14, 10, 9]
[8, 2, 3, 4, 7, 1]
[8, 7, 3, 4, 2, 1]
SORTED ARRAY : [16, 14, 10, 9, 8]
[7, 1, 3, 4, 2]
[7, 4, 3, 1, 2]
SORTED ARRAY : [16, 14, 10, 9, 8, 7]
[4, 2, 3, 1]
SORTED ARRAY : [16, 14, 10, 9, 8, 7, 4]
[3, 2, 1]
SORTED ARRAY : [16, 14, 10, 9, 8, 7, 4, 3]
[2, 1]
SORTED ARRAY : [16, 14, 10, 9, 8, 7, 4, 3, 2]
SORTED ARRAY : [16, 14, 10, 9, 8, 7, 4, 3, 2, 1]
*/

#include <iostream>
#include <vector>

using namespace std;

class HeapDataStructre {
	vector<int> arr_;

	void PrintAllElements(int size) {
		cout << "[";
		for (int i = 0; i < size; i++) {
			cout << arr_[i] << ((i + 1 < size) ? ", " : "]\n");
		}
	}

	void Heapify(int index, int heap_size) {
		int left_child = GetLeftChild(index);
		int right_child = GetRightChild(index);
		int largest = index;

		if (left_child < heap_size && arr_[left_child] > arr_[largest]) {
			largest = left_child;
		}

		if (right_child < heap_size && arr_[right_child] > arr_[largest]) {
			largest = right_child;
		}

		if (largest != index) {
			Swap(index, largest);
			PrintAllElements(heap_size);
			Heapify(largest, heap_size);
		}

	}

	void Swap(int parent, int child) {
		/* Compared already. */
		int temp = arr_[child];
		arr_[child] = arr_[parent];
		arr_[parent] = temp;
	}

	int GetParent(int index) {
		return (index - 1) / 2;
	}

	int GetLeftChild(int index) {
		return (index * 2) + 1;
	}

	int GetRightChild(int index) {
		return (index * 2) + 2;
	}

public:
	HeapDataStructre(vector<int> &A) {
		/* in c++, vector allocation operator is implemneted as deep copy */
		arr_ = A;
	}

	vector<int> GetSortedHeap() {
		vector<int> sorted_arr;

		cout << "\nBEFOR SORTING : ";
		PrintAllElements(arr_.size());
		cout << "SORTING >>\n";

		for (int i = arr_.size() - 1; i >= 0; i--) {
			sorted_arr.push_back(arr_[0]);
			cout << "SORTED ARRAY : [";
			for (int i = 0; i < sorted_arr.size(); i++) {
				cout << sorted_arr[i] << ((i + 1 < sorted_arr.size()) ? ", " : "]\n");
			}
			Swap(0, i);
			Heapify(0, i);
		}

		return sorted_arr;
	}

	void ConstructMaxHeap() {
		/* Followed the second method that is learned form last lecture */

		cout << "\nBEFOR CONSTRUCT : ";
		PrintAllElements(arr_.size());
		cout << "CONSTRUCTING >>\n";
		for (int i = (arr_.size() / 2) - 1; i >= 0; i--) {
			Heapify(i, arr_.size());
		}
	}
};

void GetVectorSize(int &size_vector) {
	cin >> size_vector;
}

void GetElements(vector<int> &A, int size) {
	A = vector<int>(size);

	for (int i = 0; i < A.size(); i++) {
		cin >> A[i];
	}
}

void PrintAllElements(const vector<int> &A) {
	cout << "[";
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << ((i + 1 < A.size()) ? ", " : "]\n");
	}
}

int main() {
	int size_vector;
	vector<int> arr;

	GetVectorSize(size_vector);
	GetElements(arr, size_vector);

	HeapDataStructre heap(arr);
	heap.ConstructMaxHeap();
	vector<int> sorted_arr = heap.GetSortedHeap();

	system("pause");
}