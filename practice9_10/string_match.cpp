#include "string_match.h"

vector<pair<int, int>> BruteSearch(char * pattern_string, char * text_string, int & cnt) {
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


/********************************************************************
* Pros:
* KMP 알고리즘은 스트링 매치의 결과를 다음 스트링 매치에 사용함으로써
* 효율적으로 스트링 매치를 할 수 있다.
* Cons:
* 하지만 텍스트에서 찾고자 하는 패턴이 2글자도 일치하는 않는 경우에서는
* KMP 알고리즘이 brute-force 방법보다 좋지 않을 수 있다.
* KMP 알고리즘은 스트링 매치를 하기에 앞서 fail function을 계산하기 위한
* 전처리 과정이 필요하기 때문이다.
********************************************************************/
vector<pair<int, int>> Kmp(char * pattern_string, char * text_string, int & cnt) {
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
		while (j > 0 && text_string[i] != pattern_string[j]) {
			cnt++;
			/*******************************************************************
			* 이 전의 스트링 매치의 결과를 다음 스트링 매치에 사용한다.
			*******************************************************************/
			j = fail[j - 1];
		}

		cnt++;
		if (text_string[i] == pattern_string[j]) {
			if (j == pattern_length - 1) {
				position.push_back({ i - pattern_length + 1, i });
				/********************************************************************* 
				* 텍스트에서 일치하는 패턴을 찾았지만, 이 후에 일치하는 패턴을 찾기 위해서
				* 찾지 못한 것 처럼 행동해야 할 필요성이 있다.
				*********************************************************************/
				j = fail[j - 1];
			} else {
				j++;
			}
		}
	}

	delete fail;

	return position;
}

vector<pair<int, int>> RabinKarp(char * pattern_string, char * text_string, int base, int mod, int & cnt) {
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

void PrintReuslt(const char * algorithm, const vector<pair<int, int>>& result, const int & comp_cnt) {
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
