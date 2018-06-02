#include "string_match.h"

vector<pair<int, int>> BruteSearch(char * pattern_string, char * text_string, int & cnt) {
	vector<pair<int, int>> position;
	int pattern_length = strlen(pattern_string);
	int text_length = strlen(text_string);

	for (int i = 0; i <= text_length - pattern_length; i++) {
		int miss_match_cnt = 0;

		for (int j = 0; j < pattern_length; j++) {
			cnt++;
			
			if (text_string[i + j] != pattern_string[j]) miss_match_cnt++;
			if (miss_match_cnt > num_allowed_missmatch) break;
			if (j == pattern_length - 1) position.push_back({ i, i + j });
		}
	}

	return position;
}


/********************************************************************
* Pros:
* KMP �˰������� ��Ʈ�� ��ġ�� ����� ���� ��Ʈ�� ��ġ�� ��������ν�
* ȿ�������� ��Ʈ�� ��ġ�� �� �� �ִ�.
* Cons:
* ������ �ؽ�Ʈ���� ã���� �ϴ� ������ 2���ڵ� ��ġ�ϴ� �ʴ� ��쿡����
* KMP �˰������� brute-force ������� ���� ���� �� �ִ�.
* KMP �˰������� ��Ʈ�� ��ġ�� �ϱ⿡ �ռ� fail function�� ����ϱ� ����
* ��ó�� ������ �ʿ��ϱ� �����̴�.
********************************************************************/
vector<pair<int, int>> Kmp(char * pattern_string, char * text_string, int & cnt) {
	vector<pair<int, int>> position;
	int pattern_length = strlen(pattern_string);
	int text_length = strlen(text_string);
	int *fail = new int[pattern_length]();
	int miss_match_cnt = 0;

	for (int i = 1, j = 0; i < pattern_length; i++) {
		while (j > 0 && pattern_string[i] != pattern_string[j]) {
			j = fail[j - 1];
		}
		if (pattern_string[i] == pattern_string[j]) fail[i] = ++j;
	}

	for (int i = 0, j = 0; i < text_length; i++) {
		while (j > 0 && text_string[i] != pattern_string[j]) {
			cnt++;

			if (miss_match_cnt < num_allowed_missmatch) {
				miss_match_cnt++;
				continue;
			}
			miss_match_cnt = 0;
			/*******************************************************************
			* �� ���� ��Ʈ�� ��ġ�� ����� ���� ��Ʈ�� ��ġ�� ����Ѵ�.
			*******************************************************************/
			j = fail[j - 1];
		}

		cnt++;
		if (text_string[i] == pattern_string[j]) {
			if (j == pattern_length - 1) {
				position.push_back({ i - pattern_length + 1, i });
				/********************************************************************* 
				* �ؽ�Ʈ���� ��ġ�ϴ� ������ ã������, �� �Ŀ� ��ġ�ϴ� ������ ã�� ���ؼ�
				* ã�� ���� �� ó�� �ൿ�ؾ� �� �ʿ伺�� �ִ�.
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