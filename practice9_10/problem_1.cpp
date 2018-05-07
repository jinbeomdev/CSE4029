/*
Student ID : 2013113504
Student Name : KIM JIN BEOM

Problem 1. String matching algorithms

Find all the pattern String from the Text String using three different
algorithms; Brute-Force(Trivial matching), KMP, Rabin-Karp
Submit the code
Submit the output
(all the positions of matches and the number of comparisons)

Input :
Text String: A STRING SEARCHING EXAMPLE CONSISTING OF A GIVEN PATTERN STRING
Pattern String: STRING
*/
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> BruteSearch(
	char *pattern_string,
	char *text_string,
	int &cnt) {
	vector<pair<int, int>> position;
	int pattern_length = strlen(pattern_string);
	int text_length = strlen(text_string);

	for (int i = 0; i <= text_length - pattern_length; i++) {
		for (int j = 0; j < pattern_length; j++) {
			cnt++;
			if (text_string[i + j] != pattern_string[j]) break;
			if (j == pattern_length - 1) position.push_back({ i, i + j });
		}
	}

	return position;
}

vector<pair<int, int>> Kmp(
	char *pattern_string,
	char *text_string,
	int &cnt) {
	vector<pair<int, int>> position;
	int pattern_length = strlen(pattern_string);
	int text_length = strlen(text_string);
	int *fail = new int[pattern_length]();
	
	for (int i = 1, j = 0; i < pattern_length; i++) {
		while (j > 0 && pattern_string[i] != pattern_string[j]) {
			j = fail[j - 1];
		}
		if (pattern_string[i] == pattern_string[j]) fail[i] = ++j;
	}

	for (int i = 0, j = 0; i < text_length; i++) {
		cnt++;
		
		while (j > 0 && text_string[i] != pattern_string[j]) {
			cnt++;
			j = fail[j - 1];
		}

		if (text_string[i] == pattern_string[j]) {
			if (j == pattern_length - 1) {
				position.push_back({ i - pattern_length + 1, i });
				j = fail[j - 1];
			} else {
				j++;
			}
		}
	}

	delete fail;

	return position;
}


vector<pair<int, int>> RabinKarp(
	char *pattern_string,
	char *text_string,
	int base,
	int mod,
	int &cnt) {
	vector<pair<int, int>> position;
	int pattern_length = strlen(pattern_string);
	int text_length = strlen(text_string);
	int pattern_hash = 0, text_hash = 0, power = 1;

	for (int i = 0; i < pattern_length; i++) {
		pattern_hash = (pattern_hash + pattern_string[pattern_length - 1 - i] * power) % mod;
		text_hash = (text_hash + text_string[pattern_length - 1 - i] * power) % mod;
		if (i < pattern_length - 1) power *= base;
	}

	for (int i = 0; i < text_length - pattern_length + 1; i++) {
		cnt++;
		if (text_hash == pattern_hash) {
			bool is_same = true;
			
			for (int j = 0; j < pattern_length; j++) {
				cnt++;
				if (text_string[i + j] != pattern_string[j]) {
					is_same = false;
					break;
				}
			}

			if (is_same) {
				position.push_back({ i , i + pattern_length - 1 });
			}

		}
			text_hash = ((text_hash - text_string[i] * power) * base + text_string[i + pattern_length]) % mod;
	}

	return position;
}

void PrintReuslt(const char *algorithm, const vector<pair<int ,int>> &result, const int &comp_cnt) {
	if (!result.size()) {
		cout << "#" << algorithm << " COMPARSION" << endl;
		cout << "Can't find the pattern string in text string" << endl;
	} else {
		cout << "#" << algorithm << " COMPARSION" << endl;
		cout << "#location ";
		for (pair<int, int> location : result) {
			cout << "{" << location.first << ", " << location.second << "} ";
		} cout << endl;
	}
	cout << "#" << algorithm << " COMPARSION COUNT : " << comp_cnt
		<< endl
		<< endl;
}

int main() {
	char text_string[] = "A STRING SEARCHING EXAMPLE CONSISTING OF A GIVEN PATTERN STRING";
	char pattern_string[] = "STRING";

	vector<pair<int, int>> brute_force_result;
	int brute_force_comp_cnt = 0;
	brute_force_result = BruteSearch(pattern_string, text_string, brute_force_comp_cnt);
	PrintReuslt("BRUTE FORCE", brute_force_result, brute_force_comp_cnt);


	vector<pair<int, int>> kmp_result;
	int kmp_comp_cnt = 0;
	kmp_result = Kmp(pattern_string, text_string, kmp_comp_cnt);
	PrintReuslt("KMP", kmp_result, kmp_comp_cnt);

	vector<pair<int, int>> rabin_karp_result;
	int rabin_karp_cnt = 0;
	rabin_karp_result = RabinKarp(pattern_string, text_string, 2, 10e8, rabin_karp_cnt);
	PrintReuslt("RABIN KARP", rabin_karp_result, rabin_karp_cnt);

	system("pause");
}