/*
Student ID : 2013113504
Student Name : KIM JIN BEOM

Question 1

Probelm 1. Implement the above-mentioned coin exchange probelm as a recursive algorithm.

1)Write pseudocode.
GREEDY(M, c, d, index, k)
   if index = 0
      n = M / c[index]
	  k.tail = n
	  return M - c[index] * n
	m = GREEDY(M, c, d, index - 1, k)
	n = m / c[index]
	k.tail = n
	return m - c[index] * n

2)Create a program and get output of input case M = 40, c = (25,20,15,10,5,1).
(You do not need to print out the required combination of coins.)
*/

#include <iostream>
#include <vector>

using namespace std;

int greedy(const int M, const vector<int> &c, int d, int index, vector<int> &k) {	
	if (index == 0) {
		int n = M / c[index];
		
		k.push_back(n);

		return M - c[index] * n;
	}

	int m = greedy(M, c, d, index - 1, k);
	int n = m / c[index];

	k.push_back(n);

	return m - c[index] * n;
}

int main() {
	int M, d;
	vector<int> c;
	vector<int> k;

	cin >> M >> d;

	c = vector<int>(d);

	for (int i = 0; i < d; i++) {
		cin >> c[i];
	}

	greedy(M, c, d, d-1, k);

	for (int i = 0; i < d; i++) {
		cout << k[i] << " ";
	}

	system("pause");
}