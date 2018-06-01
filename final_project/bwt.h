#pragma once
#ifndef BWT_H
#define BWT_H

#include <cstdint>

#include <fstream>
#include <string>
#include <vector>

struct SuffixInfo {
	uint64_t left_walk;
	std::string suffix_string;
};

struct BwtInfo {
	char gene;
	uint64_t rank;
	uint64_t left_walk;
};

class Bwt {
private:
	std::vector<BwtInfo> bwt_info;
	uint64_t p_sum[5]; //offset을 계산할 때 사용한다.
public:
	Bwt() {
		p_sum[0] = 1;
	}
	~Bwt() {}
	void GenerateBwtInfo(std::ifstream &ifs);
	static bool Comp(const SuffixInfo &a, const SuffixInfo &b);
	void PrintBwtInfo();
	bool SearchQuery(const std::string query);
};

#endif // !BWT_H
