#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long bwt_int;
typedef char bwt_char;

class Bwt {
public:
	bwt_int walk_left;
	bwt_int rank;
	bwt_int p_sum;
	bwt_char bwt;
};

void PrintRanks(const vector<pair<char, int>> &ranks) {
	cout << "RANKS" << endl;
	for (pair<char, int> rank : ranks) {
		cout << rank.first << "(" << rank.second << ")";
	} cout << endl << endl;
}

void PrintBwt(const vector<char> &bwt) {
	cout << "BWT" << endl;
	for (char c : bwt) {
		cout << c;
	} cout << endl << endl;
}

bool CompRank(const pair<char, int> &a, const pair<char, int> &b) {
	if (a.first != b.first) return a.first < b.first;
	else return a.second < b.second;
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

//int main() {
//	string original_sequence;
//
//	cin >> original_sequence;
//	original_sequence.append("$");
//
//	vector<vector<char>> suffix_table(
//		original_sequence.size(),
//		vector<char>(original_sequence.size())
//	);
//
//	for (int i = 0; i < suffix_table.size(); i++) {
//		suffix_table[i].assign(original_sequence.begin(), original_sequence.end());
//	}
//
//	/* STEP 1 */
//	for (int i = 1; i < suffix_table.size(); i++) {
//		rotate(suffix_table[i].begin(), suffix_table[i].begin() + i, suffix_table[i].end());
//	}
//	cout << "STEP 1" << endl;
//	PrintSuffixTable(suffix_table);
//
//	/* STEP 2 */
//	sort(suffix_table.begin(), suffix_table.end(), Comp);
//	cout << "STEP 2" << endl;
//	PrintSuffixTable(suffix_table);
//
//	/* STEP 3 */
//	vector<char> bwt(suffix_table.size());
//	for (int i = 0; i < bwt.size(); i++) {
//		bwt[i] = suffix_table[i].back();
//	}
//	cout << "STEP 3" << endl;
//	PrintBwt(bwt);
//
//	/* STEP 4 */
//	cout << "STEP 4" << endl;
//	vector<pair<char, int>> ranks(bwt.size());
//	vector<bool> visited(bwt.size(), false);
//	for (int i = 0; i < bwt.size(); i++) {
//		int rank = 0;
//
//		for (int j = 0; j < bwt.size(); j++) {
//			if (!visited[j] && bwt[i] == bwt[j]) {
//				ranks[j] = make_pair(bwt[j], rank);
//				rank++;
//			}
//		}
//	}
//	PrintRanks(ranks);
//
//	vector<pair<char, int>> first_column = ranks;
//	sort(first_column.begin(), first_column.end(), CompRank);
//
//	PrintRanks(first_column);
//
//	/* STEP 5 */
//	cout << "STEP 5" << endl;
//	char next_char = ranks[0].first;
//	char next_rank = ranks[0].second;
//	vector<char> find;
//	while (next_char != '$') {
//		find.push_back(next_char);
//
//		for (char c : find) {
//			cout << c;
//		} cout << endl;
//
//		for (int i = 0; i < first_column.size(); i++) {
//			if (first_column[i].first == next_char &&
//				first_column[i].second == next_rank) {
//				next_char = ranks[i].first;
//				next_rank = ranks[i].second;
//				break;
//			}
//		}
//	}
//
//	system("pause");
//	return 0;
//}