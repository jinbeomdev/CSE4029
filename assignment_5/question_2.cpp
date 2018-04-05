/*
Student ID : 2013113504
Studnet Name : KIM JIN BEOM

Question 2:
Implement a program that outputs the coin combination and the minimum
number of coins using the Dynamic Programming Algorithm.

1)Write a Pseudo-code
COIN_CHANGE_PROBLEM()
  for i=0 to N
	  for j=0 to M
	    if i - j >= 0
		    dp[i] = min(dp[i], dp[i - j] + 1)

2)Express the execution time of the algorithm in Big-O.
O(md), m=money, d=number of coins

3)Implement the program.
4)Write the output value when the program is run when M=11, c=[1,3,5]
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	const int INF = 10e6;
	int num_coins;
	int money;

	std::cin >> money;
	std::cin >> num_coins;

	money++; /* for zero */	
	std::vector<int> coins = std::vector<int>(num_coins);
	std::vector<int> dp = std::vector<int>(money, INF);

	for (int i = 0; i < num_coins; i++) {
		std::cin >> coins[i];
	}

	dp[0] = 0;

	for (int i = 1; i < money; i++) {
		for (int coin : coins) {
			if (i - coin >= 0) {
				dp[i] = std::min(dp[i], dp[i - coin] + 1);
			}
		}
	}

	//std::cout << dp[money - 1];

	for (int num_coin : dp) {
		std::cout << num_coin << " ";
	}
	
	std::system("pause");
	return 0;
}