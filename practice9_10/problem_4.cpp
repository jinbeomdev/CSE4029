/*
Student ID : 2013113504
Student Name : KIM JIN BEOM

문제4.
스트링 매칭 알고리즘 구현(Project Preparation3)

(A), (B) 프로그램 두 개의 코드와 n=100,000, pattern = ACCGTAT일
때의 input.txt와 output.txt를 제출하시오.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <fstream>

#include "string_match.h"

const int kTextStringSize = 100000;

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
	FILE *input_file = fopen("input.txt", "r");
	ofstream output_file("probelm_4_ouput.txt");

	if (!input_file) {
		printf("%s",
			"failed to open file\n");
	}

	/* Read gene sequence from file */
	char pattern_string[] = "ACCGTAT";
	char text_string[kTextStringSize];
	for (int i = 0; i < kTextStringSize; i++) {
		text_string[i] = fgetc(input_file);
	}
	text_string[kTextStringSize - 1] = '\0';

	printf("%s%s\n%s%s\n\n",
		"TEXT STRING : ", text_string,
		"PATTERN STRING : ", pattern_string);

	vector<pair<int, int>> brute_force_result;
	int brute_force_comp_cnt = 0;
	brute_force_result = BruteSearch(pattern_string, text_string, brute_force_comp_cnt);
	PrintReuslt(output_file, "BRUTE FORCE", brute_force_result, brute_force_comp_cnt);

	vector<pair<int, int>> kmp_result;
	int kmp_comp_cnt = 0;
	kmp_result = Kmp(pattern_string, text_string, kmp_comp_cnt);
	PrintReuslt(output_file, "KMP", kmp_result, kmp_comp_cnt);

	system("pause");
}