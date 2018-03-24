/*
Student ID : 2013113504
Student Name : KIM JIN BEOM

Question 1. Merge Sort
We have learned recursive merge sort. Let's change this into iterative merge sort.

Problem 1. Implement recursive merge sort.
1) submit the code
2) print the output for input A = [30, 20, 40, 35, 5, 50, 45, 10, 25, 15]. Show the values for each step.

Probelm 2. Change the above code into iterative merge sort
1) submit the code
2) print the output for input A = [30, 20, 40, 35, 5, 50, 45, 10, 25, 15]. Show the values for each step.

input :
10
30 20 40 35 5 50 45 10 25 15

output :
EACH STEP OF RECURSIVE MERGE SORT
!!--------------------------------------!!
STEP >>
[20, 30] (0~1)
[20, 30, 40] (0~2)
[5, 35] (3~4)
[5, 20, 30, 35, 40] (0~4)
[45, 50] (5~6)
[10, 45, 50] (5~7)
[15, 25] (8~9)
[10, 15, 25, 45, 50] (5~9)
[5, 10, 15, 20, 25, 30, 35, 40, 45, 50] (0~9)

RESULT OF RECURSIVE MERGE SORT >>
[5, 10, 15, 20, 25, 30, 35, 40, 45, 50]
!!--------------------------------------!!

EACH STEP OF ITERATIVE MERGE SORT
!!--------------------------------------!!
STEP >>
[20, 30] (0~1)
[35, 40] (2~3)
[5, 50] (4~5)
[10, 45] (6~7)
[15, 25] (8~9)
[20, 30, 35, 40] (0~3)
[5, 10, 45, 50] (4~7)
[15, 25] (8~9)
[5, 10, 20, 30, 35, 40, 45, 50] (0~7)
[15, 25] (8~9)
[5, 10, 15, 20, 25, 30, 35, 40, 45, 50] (0~9)

RESULT OF ITERATIVE MERGE SORT >>
[5, 10, 15, 20, 25, 30, 35, 40, 45, 50]
!!--------------------------------------!!
*/
#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

void print_head(string head) {
	cout << "EACH STEP OF " << head  << " MERGE SORT" << endl <<
		"!!--------------------------------------!!" << endl <<
		"STEP >> \n";
}

void print_array_elements(string s, const vector<int> &A) {
	cout << "\nRESULT OF " << s << " MERGE SORT >> " << endl;


	cout << "[";
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << ((i + 1 < A.size()) ? ", " : "] ");
	}

	cout << "\n!!--------------------------------------!!\n\n";
}

void print_result_merge(const vector<int> &A, const int left, const int right) {
	cout << "[";
	for (int i = left; i <= right; i++) {
		cout << A[i] << ((i + 1 <= right) ? ", " : "] ");
	}
	cout << "(" << left << "~" << right << ")\n";
}

void merge(vector<int> &A, const int left, const int mid, const int right) {
	int i = left, j = mid + 1, k = 0;
	const int B_SIZE = right - left + 1;
	vector<int> B = vector<int>(B_SIZE);

	while (i <= mid && j <= right) {
		if (A[i] < A[j]) {
			B[k++] = A[i++];
		}
		else {
			B[k++] = A[j++];
		}
	}

	while (i <= mid) {
		B[k++] = A[i++];
	}

	while (j <= right) {
		B[k++] = A[j++];
	}


	for (int walker = left, l = 0; walker <= right; walker++, l++) {
		A[walker] = B[l];
	}

	print_result_merge(A, left, right);
}

void merge_sort(vector<int> &A, const int left, const int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(A, left, mid);
		merge_sort(A, mid + 1, right);
		merge(A, left, mid, right);
	}
}

vector<int> recursive_merge_sort(const vector<int> &A) {
	print_head("RECURSIVE");

	vector<int> sorted_A(A);

	merge_sort(sorted_A, 0, sorted_A.size() - 1);

	return sorted_A;
}

vector<int> iteratvie_merge_sort(const vector<int> &A) {
	print_head("ITERATIVE");

	vector<int> sorted_A(A);

	for (int sub_array_size = 1; sub_array_size < sorted_A.size(); sub_array_size *= 2) {
		for (int left = 0; left < sorted_A.size(); left += 2 * sub_array_size) {
			int right = min(left + 2 * sub_array_size - 1, (int)sorted_A.size() - 1);
			int mid = min(left + sub_array_size - 1, (int)sorted_A.size() - 1);
			
			merge(sorted_A, left, mid, right);
		}
	}

	return sorted_A;
}

int main() {
	int N;
	vector<int> A;
	vector<int> result_recursive_merge_sort;
	vector<int> result_iterative_merge_sort;
	cin >> N;

	A = vector<int>(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	result_recursive_merge_sort = recursive_merge_sort(A);
	print_array_elements("RECURSIVE", result_recursive_merge_sort);

	result_iterative_merge_sort = iteratvie_merge_sort(A);
	print_array_elements("ITERATIVE", result_recursive_merge_sort);

	return 0;
}