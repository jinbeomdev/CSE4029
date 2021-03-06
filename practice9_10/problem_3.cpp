/*
Student ID : 2013113504
Student Name : KIM JIN BEOM

Project preparation2

Find a random pattern composed of A/C/G/T of length m<=30 from input.
txt using Brute-Force(Trivial matching), and your own algorithm.

You can use any algorithm such as Rabin-Karp, KMP or etc,
but it should work better in respect to efficiency or accuracy.
Write the pros and Cons of your algorithm in��detail��.
Submit the code with detailed comments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

#include "string_match.h"

const int kTextStringSize = 1000000;

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
	ofstream output_file("probelm_3_ouput.txt");

	if (!input_file) {
		printf("%s",
			"failed to open file\n");
	}
	
	/* Read gene sequence from file */
	char pattern_string[] = "GAACCTAGCTTCGC";
	char text_string[kTextStringSize];
	for (int i = 0; i < kTextStringSize; i++) {
		text_string[i] = fgetc(input_file);
	}
	text_string[kTextStringSize - 1] = '\0';

	/*
	printf("%s%s\n%s%s\n\n",
		"TEXT STRING : ", text_string,
		"PATTERN STRING : ", pattern_string);
	*/

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