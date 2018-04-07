/*
Student ID : 2013113504
Studnet Name : Stone Problem

Question 3:
Stone Problem

there are two boxes, each containing m and n stones. One day,
Yeonhee and Chul-soo suggested a fun game with a box. The rules of
the game are as follows. Starting with Young-hee, you can take one
stone out of the one-sided or one stone out of each box. The stones
can not be put back into the box. The last person to take out the
stone wings the game. Use a dynamic programming algorithm to build
a winning strategy.

1)Who starts the game first determines the win or lose of the game?
2)Use dynamic programming to create a winning strategy table for m
and n in the range 1 to 5. For example, when m = 5, n = 3, you should
be able to see who will win during the game.
3)Write this strategy in pseudocode
4)Implement this strategy and print out who will win when m=10, n=7.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int m, n;

	cin >> m >> n;

	vector<vector<char>> winning_strategy_table
		= vector<vector<char>>(m, vector<char>(n));

	winning_strategy_table[0][0] = 'L';
	for (int i = 1; i < m; i++) {
		if (i % 2 == 0) {
			winning_strategy_table[i][0] = 'L';
		} else {
			winning_strategy_table[i][0] = 'W';
		}
	}

	for (int i = 1; i < n; i++) {
		if (i % 2 == 0) {
			winning_strategy_table[0][i] = 'L';
		} else {
			winning_strategy_table[0][i] = 'W';
		}
	}

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (winning_strategy_table[i - 1][j - 1] == 'W' &&
				winning_strategy_table[i - 1][j] == 'W' &&
				winning_strategy_table[i][j - 1] == 'W') {
				winning_strategy_table[i][j] = 'L';
			} else {
				winning_strategy_table[i][j] = 'W';
			}
		}
	}

	cout << "  ";
	for (int i = 0; i < n; i++) {
		cout << i << " ";
	}
	cout << endl;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 0) cout << i << " ";
			cout << winning_strategy_table[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}