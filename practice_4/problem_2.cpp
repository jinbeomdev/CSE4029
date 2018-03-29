/*
Student ID : 2013113504
Student Name : KIM JIN BEOM

Problem 2

Fibonacci¡¯s sequence

Fibonacci¡¯s sequence has been introduced my a mathematician named Leonardo Pisano
Fibonacci at 13th century. He tried to compute the number of total rabbits
(parents and their children) by each year from a pair of rabbits.
Solve the Fibonacci problem below

Assumption: One pair of adult rabbits could create a new pair of rabbits
in about the same time that it takes bunnies to grow into adults. Thus,
in a given period, each pair of adult rabbits produces a new pair of baby rabbits,
and all baby rabbits grow into adult rabbits.

input :
20

ouput :
1:0
2:1
3:1
4:2
5:3
6:5
7:8
8:13
9:21
10:34
11:55
12:89
13:144
14:233
15:377
16:610
17:987
18:1597
19:2584
20:4181
*/
#include <iostream>

using namespace std;

int Fibonacci(const int n, int dp[]) {
	if (n == 0) {
		return dp[0];
	}

	if (n == 1) {
		return dp[1];
	}
	
	dp[n] = Fibonacci(n - 1, dp) + Fibonacci(n - 2, dp);

	return dp[n];
}

int main() {
	int num;
	int *dp;

	cin >> num;

	dp = new int[num];
	dp[0] = 0;
	dp[1] = 1;

	Fibonacci(num, dp);

	for (int i = 0; i < num; i++) {
		cout << i + 1 << ":" << dp[i] << endl;
	}

	system("pause");

	/* Can't deallocate dp memory. */
	//delete[] dp;
}