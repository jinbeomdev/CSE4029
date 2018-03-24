/*
Student ID : 2013113504
Name : KIM JIN BEOM
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	vector<bool> A;

	cin >> N;

	A = vector<bool>(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int n;

		cin >> n;

		A[n] = true;
	}

	for (int i = 1; i <= N; i++) {
		if (A[i] == false) {
			cout << i;
			break;
		}
	}

	system("pause");
}