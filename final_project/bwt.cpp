#include "bwt.h"
#include <cassert>
#include <algorithm>
#include <iostream>

void Bwt::GenerateBwtInfo(std::ifstream & ifs) {
		std::string genome;

		while (true) {
			char gene;
			ifs >> gene;
			if (ifs.eof()) break;
			genome += gene;
		}
		genome += "$";
		//genome += '\0';
	
		std::vector<SuffixInfo> suffix_table(genome.size());
	
		for (size_t i = 0; i < suffix_table.size(); i++) {
			suffix_table[i].left_walk = i;
			suffix_table[i].suffix_string.assign(genome.begin(), genome.end());
		}
	
		for (size_t i = 1; i < suffix_table.size(); i++) {
			rotate(suffix_table[i].suffix_string.begin(), suffix_table[i].suffix_string.begin() + i, suffix_table[i].suffix_string.end());
		}
	
		std::sort(suffix_table.begin(), suffix_table.end(), Comp);
	
		bwt_info = std::vector<BwtInfo>(suffix_table.size());
		uint64_t num_gene[4] = { 0, };
		for (size_t i = 0; i < bwt_info.size(); i++) {
			bwt_info[i].gene = suffix_table[i].suffix_string.back();
			bwt_info[i].left_walk = suffix_table[i].left_walk;

			switch (bwt_info[i].gene) {
			case 'A':
				bwt_info[i].rank = num_gene[0]++;
				break;
			case 'C':
				bwt_info[i].rank = num_gene[1]++;
				break;
			case 'G':
				bwt_info[i].rank = num_gene[2]++;
				break;
			case 'T':
				bwt_info[i].rank = num_gene[3]++;
				break;
			case '$':
				break;
			default:
				assert(false);
			}
		}

		for (int i = 1; i <= 4; i++) {
			p_sum[i] = p_sum[i - 1] + num_gene[i - 1];
		}
}

bool Bwt::Comp(const SuffixInfo &a, const SuffixInfo &b) {
	for (size_t i = 0; i < a.suffix_string.size(); i++) {
		if (a.suffix_string[i] != b.suffix_string[i]) return a.suffix_string[i] < b.suffix_string[i];
	}
	return true;
}

void Bwt::PrintBwtInfo() {
	for (BwtInfo info : bwt_info) {
		std::cout << info.left_walk << " " << info.gene << "(" << info.rank << ")" << std::endl;
	}
}
