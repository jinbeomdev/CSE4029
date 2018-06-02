/*
Student ID : 201313504
Student Name : KIM JIN BEOM

Create a reference genome similar to the 1,000,000 input
sequence that we made in the last project.

Try to create a reference genome similar to the input
sequence. You can create reference genome by
changing 4-5milion genes(creating mismathces) from
my genome sequence. Look up the random pattern
(created in project 2 in slide 9) in the reference genome.
print index! At this point, implement finding a string by
allowing up two mismatches. (When cutting a my genome
to make a short read, make it repeat the length I
from any random position in my genome. Make as many
as you like at least ten times in each postion.)

Implement your code
increase n 10000 by 10 times
increase i from 5 to 30 (example i = 5, 10, 15, 20, 30)
- show the running time and compare it with the one
from trivial mapping algorithm
- show the accuracy and compare it with the one from
trivial mapping algorithm
- use graph to show your results.
*/

#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <vector>
#include <string>
#include <iomanip>

#include "string_match.h"

using namespace std;

const int genome_size = 1000000;
char *reference_genome;
char *my_genome;

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

char GetRandomGene() {
	char gene;
	switch (rand() % 4) {
	case 0:
		gene = 'A';
		break;
	case 1:
		gene = 'C';
		break;
	case 2:
		gene = 'G';
		break;
	case 3:
		gene = 'T';
		break;
	default:
		assert(false);
	}
	return gene;
}

int main() {
	reference_genome = new char[genome_size];

	srand(time(NULL));
	for (int i = 0; i < 1000000; i++) {
		char gene = GetRandomGene();
		reference_genome[i] = gene;
	}

	for (int i = 10000; i < 1000000; i *= 10) {
		for (int j = 5; j < 30; j += 5) {
			char *pattern_string = new char[j];
			for (int k = 0; k < j; k++) {
				pattern_string[k] = GetRandomGene();
			}
			pattern_string[j - 1] = '\0';
			my_genome = new char[i];

			copy(reference_genome, reference_genome + i, my_genome);
			my_genome[i] = '\0';

			int num_miss_matching = int(i * 0.05);
			for (int k = 0; k < num_miss_matching; k++) {
				int miss_matching_idx = rand() % i;
				while (my_genome[miss_matching_idx] == reference_genome[miss_matching_idx]) {
					my_genome[miss_matching_idx] = GetRandomGene();
				}
			}

			string output_file_name = to_string(i) + string("_") + to_string(j) + string(".txt");
			ofstream output_file(output_file_name);

			output_file << "#MY GENOME" << endl << my_genome << endl << endl;
			output_file << "#PATTERN" << endl <<  pattern_string << endl << endl;

			vector<pair<int, int>> brute_force_result;
			int brute_force_comp_cnt = 0;
			time_t start = time(0);
			brute_force_result = BruteSearch(pattern_string, my_genome, brute_force_comp_cnt);
			time_t end = time(0);
			double diff_time = difftime(start, end);
			PrintReuslt(output_file, "BRUTE FORCE", brute_force_result, brute_force_comp_cnt);
			cout << "SIZE" << brute_force_comp_cnt << endl;
			output_file << "TIME" << fixed << setprecision(2) <<  difftime << endl << endl;

			vector<pair<int, int>> kmp_result;
			int kmp_comp_cnt = 0;
			start = time(0);
			kmp_result = Kmp(pattern_string, my_genome, kmp_comp_cnt);
			end = time(0);
			diff_time = difftime(start, end);
			PrintReuslt(output_file, "KMP", kmp_result, kmp_comp_cnt);
			cout << "SIZE" << kmp_comp_cnt << endl << endl;
			output_file << "TIME" << fixed << setprecision(2) << difftime << endl << endl;
		}
	}

	system("pause");
}