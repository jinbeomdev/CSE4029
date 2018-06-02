#pragma once
#ifndef STRING_MATCH_H
#define STRING_MATCH_H

#include <iostream>
#include <vector>

using namespace std;

const int num_allowed_missmatch = 2;

vector<pair<int, int>> BruteSearch(
	char *pattern_string,
	char *text_string,
	int &cnt);

vector<pair<int, int>> Kmp(
	char *pattern_string,
	char *text_string,
	int &cnt);

#endif // !STRING_MATCH_H