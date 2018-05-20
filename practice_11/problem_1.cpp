/*
Student ID : 2013113504
Student Name : KIM JIN BEOM

Question 1 :
For T = missisippi, find the BWT(T) and use it to
find the original sequence T. Explain the way to find
the original sequence T, Use char to show it!)

suffix table
T = missippi, S = 8
[0] $missippi
[1] i$missipp
[2] pi$missip
[3] ppi$missi
[4] ippi$miss
[5] sippi$mis
[6] ssippi$mi
[7] issippi$m
[8] missippi$

implement the code and print the result
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void PrintBwt(const vector<char> &bwt) {
	cout << "BWT" << endl;
	for (char c : bwt) {
		cout << c;
	} cout << endl << endl;
}

bool Comp(const vector<char> &a, const vector<char> &b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) return a[i] < b[i];
	}
	return true;
}

void PrintSuffixTable(const vector<vector<char>> &suffix_table) {
	cout << "SUFFIX TABLE" << endl;
	for (const vector<char> &suffix_array : suffix_table) {
		for (const char &c : suffix_array) {
			cout << c;
		} cout << endl;
	} cout << endl;
}

int main() {
	string original_sequence;
	
	cin >> original_sequence;
	original_sequence.append("$");

	vector<vector<char>> suffix_table(
		original_sequence.size(),
		vector<char>(original_sequence.size())
	);

	for (int i = 0; i < suffix_table.size(); i++) {
		suffix_table[i].assign(original_sequence.begin(), original_sequence.end());
	}
	
	for (int i = 1; i < suffix_table.size(); i++) {
		rotate(suffix_table[i].begin(), suffix_table[i].begin() + i, suffix_table[i].end());
	}
	
	sort(suffix_table.begin(), suffix_table.end(), Comp);

	PrintSuffixTable(suffix_table);

	vector<char> bwt(suffix_table.size());
	for (int i = 0; i < bwt.size(); i++) {
		bwt[i] = suffix_table[i].back();
	}

	PrintBwt(bwt);
	
	system("pause");
	return 0;
}