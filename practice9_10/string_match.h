#pragma once
#ifndef STRING_MATCH_H
#define STRING_MATCH_H

#include <iostream>
#include <vector>

using namespace std;


vector<pair<int, int>> BruteSearch(
	char *pattern_string,
	char *text_string,
	int &cnt);

vector<pair<int, int>> Kmp(
	char *pattern_string,
	char *text_string,
	int &cnt);


vector<pair<int, int>> RabinKarp(
	char *pattern_string,
	char *text_string,
	int base,
	int mod,
	int &cnt);

void PrintReuslt(
	const char *algorithm,
	const vector<pair<int, int>> &result,
	const int &comp_cnt);

#endif // !STRING_MATCH_H