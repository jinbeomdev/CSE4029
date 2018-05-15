/*
Student ID : 2013113504
Student Name : KIM JIN BEOM

Project preparation3

increase n 10000 by 10 times
increase m from 5 to 30 (example m=5,10,15,20,40)
- show the number of comparison and compare it with the one from trivial mapping algorithm
- show the accuracy and compare it with the one from trivial mapping algorithm
- use graph to show your results.

해석 :
n을 10000부터 10배씩 증가해 가면서, 각각에 대해 m을 5에서 30까지 적당히(예를 들어 m=5,10,15,20,40)
늘려가면서 수행시간(시간단위는 비교가 보여질 수 있는 정도로 적절하게 각자 정할 것)을 측정하고
이를 직선적 방법으로 구현한 것과 비교하여 그래프로 그리시오.

이때 수행시간이 너무 길어지면(예를 들어 30분 이상) n을 그만 증가 시켜도 됩니다.
그래프를 그리는 방식은 각자 고민해보고 알아보기 편하도록 그리시오.
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