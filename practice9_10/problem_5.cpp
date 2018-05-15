/*
Student ID : 2013113504
Student Name : KIM JIN BEOM

Project preparation3

increase n 10000 by 10 times
increase m from 5 to 30 (example m=5,10,15,20,40)
- show the number of comparison and compare it with the one from trivial mapping algorithm
- show the accuracy and compare it with the one from trivial mapping algorithm
- use graph to show your results.

�ؼ� :
n�� 10000���� 10�辿 ������ ���鼭, ������ ���� m�� 5���� 30���� ������(���� ��� m=5,10,15,20,40)
�÷����鼭 ����ð�(�ð������� �񱳰� ������ �� �ִ� ������ �����ϰ� ���� ���� ��)�� �����ϰ�
�̸� ������ ������� ������ �Ͱ� ���Ͽ� �׷����� �׸��ÿ�.

�̶� ����ð��� �ʹ� �������(���� ��� 30�� �̻�) n�� �׸� ���� ���ѵ� �˴ϴ�.
�׷����� �׸��� ����� ���� ����غ��� �˾ƺ��� ���ϵ��� �׸��ÿ�.
*/

#include <cstdio>
#include <fstream>
#include <cassert>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

#include "string_match.h"

using namespace std;

void PrintReuslt(ofstream &output_file, const char * algorithm, const vector<pair<int, int>>& result, const int & comp_cnt) {
	if (!result.size()) {
		output_file << "#" << algorithm << " COMPARSION" << endl;
		output_file << "Can't find the pattern string in text string" << endl;
	} else {
		output_file << "#" << algorithm << " COMPARSION" << endl;
		output_file << "#location ";
		for (pair<int, int> location : result) {
			output_file << "{" << location.first << ", " << location.second << "} ";
		} output_file << endl;
	}
	output_file << "#" << algorithm << " COMPARSION COUNT : " << comp_cnt
		<< endl
		<< endl;
}


int main() {

	ifstream input_file("input.txt");

	if (!input_file) {
		printf("%s",
			"failed to open file\n");
		assert(false);
	}

	srand(time(NULL));

	for (int pattern_size = 5; pattern_size <= 30; pattern_size += 5) {
		char *pattern_string = new char[pattern_size];

		for (int i = 0; i < pattern_size - 1; i++) {
			switch (rand() % 4)
			{
			case 0:
				pattern_string[i] = 'A';
				break;
			case 1:
				pattern_string[i] = 'C';
				break;
			case 2:
				pattern_string[i] = 'G';
				break;
			case 3:
				pattern_string[i] = 'T';
				break;
			default:
				assert(false);
			}
		}
		pattern_string[pattern_size - 1] = '\0';

		for (int text_size = 10000; text_size <= 1000000; text_size *= 10) {
			char *text_string = new char[text_size];

			if (!input_file.read(text_string, text_size - 1)) {
				assert(false);
			}
			text_string[text_size - 1] = '\0';
			input_file.seekg(0, std::ios::beg);

			string output_file_name = to_string(text_size) + string("_") + to_string(pattern_size) + string(".txt");
			ofstream output_file(output_file_name);

			output_file << text_string << endl;
			output_file << pattern_string << endl << endl;

			vector<pair<int, int>> brute_force_result;
			int brute_force_comp_cnt = 0;
			brute_force_result = BruteSearch(pattern_string, text_string, brute_force_comp_cnt);
			PrintReuslt(output_file, "BRUTE FORCE", brute_force_result, brute_force_comp_cnt);

			vector<pair<int, int>> kmp_result;
			int kmp_comp_cnt = 0;
			kmp_result = Kmp(pattern_string, text_string, kmp_comp_cnt);
			PrintReuslt(output_file, "KMP", kmp_result, kmp_comp_cnt);


			/*
			printf("%s%d, %s%d\n",
				"#TEXT SIZE : ", text_size, "#PATTERN SIZE : ", pattern_size);
			PrintReuslt("BRUTE FORCE", brute_force_result, brute_force_comp_cnt);
			PrintReuslt("KMP", kmp_result, kmp_comp_cnt);
			*/

			delete[] text_string;
		}

		delete[] pattern_string;
	}

	system("pause");
}