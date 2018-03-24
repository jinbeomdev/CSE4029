/*
Student ID : 2013113504
Name : KIM JIN BEOM

Coin change problem
1. Write a pseudo code for GreedyBetterChange.
for i = 1 to d
   Ki = M / Ci
   M = M - Ci * Ki
return (K1, K2, ..., Kd)

2. Implement GreedyBetterChange in programming language, and submit the result for M=40, c=(25,20,10,5,1)

3. Write a pseudo code for BruteForceChange.
smallestNumberOfCoins = INF
   for each(K1,K2,...,Kd) from(0,...,0) to (M/Ci,...,M/Cd)
      valueOfCoins = ¥Ò(i=1~d)CiKi
	     if valueOfCoins = M
		    numberOfCoins = ¥Ò(i=1~d)Ki
			if numberOfCoins < smallestNumberOfCoins
			   smallestNumberOfCoins = numberOfCoins
			   bestChange = (K1,K2,...,Kd)
return bestChange

4. Implement BruteForceChange in programming language, and submit the result for M=40, c=(25,20,10,5,1)

5. In the lecture, we have seen that the algorithm sometimes gives incorrect answer, for example when M=40 and  c=(25,20,10,5,1).
To get the correct result for any M, we need to add a new coin c6 for the GreedyBetterChange algorithm.
What should c6 be? If there are several possible values, please write all of them.
15, 40

6. For M=1, 2,¡¦, 100, compare the results of GreedyBetterChange(#2) and BruteForceChange(#4), when c=(25,20,10,5,1)

7. For M=1, 2,¡¦, 100, compare the results of GreedyBetterChange(#2) and BruteForceChange(#4), when you add the coin c6 to c
*/

#include <iostream>
#include <vector>
#include <algorithm> //min
#include <functional> //greater
using namespace std;

vector<int> greedy_better_change(const int M, const vector<int> &c, const int d) {
	vector<int> k = vector<int>(d);
	int _M = M;
	for (int i = 0; i < d; i++) {
		k[i] = _M / c[i];
		_M = _M - c[i] * k[i];
	}

	return k;
}

vector<int> brute_force_change(const int M, const vector<int> &c, const int d) {
	int smallest_number_of_coins = (int)10e6;
	vector<int> best_change = vector<int>(d);

	for (int i = 0; i < d; i++) {
		int _M = M;
		int value_of_coins = 0;
		int number_of_coins = 0;
		vector<int> k = vector<int>(d, 0);

		for (int j = i; j < d; j++) {
			k[j] = _M / c[j];
			_M = _M - c[j] * k[j];
			value_of_coins += c[j] * k[j];
		}

		if (value_of_coins == M) {
			for (int i = 0; i < d; i++) {
				number_of_coins += k[i];
			}
		}

		if (number_of_coins < smallest_number_of_coins) {
			smallest_number_of_coins = number_of_coins;
			copy(k.begin(), k.end(), best_change.begin());
		}
	}

	return best_change;
}

int main() {
	int M;
	int d; //number of coins

	cin >> d;

	vector<int> c = vector<int>(d);

	for (int i = 0; i < d; i++) {
		cin >> c[i];
	}

	for (int i = 1; i < 100; i++) {
		M = i;
		vector<int> result_greedy_better_change = greedy_better_change(M, c, d);
		vector<int> result_brute_force_change = brute_force_change(M, c, d);

		if (result_greedy_better_change != result_brute_force_change) {
			cout << "When M is " << M << " result is not equal\n";
			for (int num_coins : result_greedy_better_change) {
				cout << num_coins << " ";
			} cout << endl;

			for (int num_coins : result_brute_force_change) {
				cout << num_coins << " ";
			} cout << endl;
		}
	}
}