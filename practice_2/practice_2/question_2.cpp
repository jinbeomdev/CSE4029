/*
Student ID : 2013113504
Student Name : KIM JIN BEOM

Question 2(selection sort)

Problem2. We have learned iterative algorithm of selection sort.

1. Implement the iterative selection sort
1) Write pseudocode
SELECTION_SORT(A)
   for i = 0 to A.length - 1
      m = i
	  for j = i + 1 to A.length
	     if A[m] > A[j]
		    m = j
		 if m != i
		    SWAP(A[i], A[m]

2) Write the program and submit the result for the input A = [30,20,40,10,5,10,30,15]. For each step print array A to show how the elements of A changes.

2. Implement the recursive selection sort

1) Write pseudocode
FIND_MIN_INDEX(A, i)
   m = i
   if i = A.length
      return m
   j = FIND_MIN_INDEX(A, i + 1)
   if A[m] > A[j]
      m = j
   return m

RECURSIVE_SELECTION_SORT(A, i)
   if index = A.length
      return
   m = FIND_MIN_INDEX(A, i)
   if m != i
      SWAP(A[m], A[i])
   RECURSIVE_SELECTION_SORT(A, i + 1)

2) Write the program and submit the result for the input A = [30,20,40,10,5,10,30,15]. For each step print array A to show how the elements of A changes.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_elements(const vector<int> &A) {
	for (int element : A) {
		cout << element << " ";
	}
}

void swap(int &a, int &b) {
	if (a > b) {
		int temp = b;
		b = a;
		a = temp;
	}
}

int find_min_index(const vector<int> &A, const int index) {
	int min_index = index;

	if (index == A.size() - 1) {
		return index;
	}

	int temp = find_min_index(A, index + 1);
	if (A[min_index] > A[temp]) {
		min_index = temp;
	}
	
	return min_index;
}

void recursive_selection_sort(vector<int> &A, const int index) {
	if (index == A.size() - 1) {
		return;
	}

	int min_index = find_min_index(A, index);

	if (min_index != index) {
		swap(A[index], A[min_index]);
	}

	//print elements of temp_A every each step
	cout << "step " << index + 1 << " : ";
	print_elements(A);
	cout << "(switched " << index << " with " << min_index << ")" << endl;
	recursive_selection_sort(A, index + 1);
}

vector<int> insertion_sort(const vector<int> &A) {
	vector<int> temp_A;
	temp_A.resize(A.size());
	copy(A.begin(), A.end(), temp_A.begin());
	
	for (int i = 0; i < temp_A.size() - 1; i++) {
		int min_index = i;
		
		for (int j = i + 1; j < temp_A.size(); j++) {
			if (temp_A[min_index] > temp_A[j]) {
				min_index = j;
			}
		}

		if (min_index != i) {
			swap(temp_A[i], temp_A[min_index]);
		}

		//print elements of temp_A every each step
		cout << "step " << i + 1 << " : ";
		print_elements(temp_A);
		cout << "(switched " << i << " with " << min_index << ")" << endl;
	}

	return temp_A;
}

int main() {
	int n;
	vector<int> A;

	cin >> n;

	A = vector<int>(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}


	cout << "iterative selection sort" << endl;
	//cout << "recursive selection sort" << endl;
	cout << "step 0 : ";
	print_elements(A);
	cout << endl;
	
	/* select the function what you want */
	vector<int> result_a = insertion_sort(A);
	//recursive_selection_sort(A, 0);

	system("pause");
}