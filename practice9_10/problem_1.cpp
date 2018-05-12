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

/* standard library */
#include <iostream>
#include <vector>

#include "string_match.h"

using namespace std;

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