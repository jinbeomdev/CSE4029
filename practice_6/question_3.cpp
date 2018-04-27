/*
Student ID : 2013113504
Student Name : KIM JIN BEOM

Question 3:
Dynamic Programming

There are three operation that can be use for integer X.
-if X divides by 3, divide by 3
-if X divides by 2, divide by 2
-Subtract by 1

Given an integer N, I would like to make one by using these three operations
appropriately. Print the minimum number of times to use the operation.
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int kMaxInteger = 100;
const int kOperationSize = 3;
const int kInf = 10e6;

int main() {
	int N;
	int dp[kMaxInteger];
	int result = kInf;

	cin >> N;
	fill(dp, dp + kMaxInteger, kInf);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= N; i++) {
		dp[i] = min(dp[i], dp[i - 1] + 1);

		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}

		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}

	cout << dp[N] << endl;
	system("pause");
}