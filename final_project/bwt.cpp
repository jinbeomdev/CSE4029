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

bool Bwt::SearchQuery(const std::string query) {
	uint64_t start;
	uint64_t end;
	switch (query.back()) {
	case 'A':
		start = p_sum[0];
		end = p_sum[1];
		break;
	case 'C':
		start = p_sum[1];
		end = p_sum[2];
		break;
	case 'G':
		start = p_sum[2];
		end = p_sum[3];
		break;
	case 'T':
		start = p_sum[3];
		end = p_sum[4];
		break;
	default:
		assert(false);
	}

	std::cout << "SEARCHING..." << std::endl;
	std::cout << "QUERY : " << query << std::endl;
	for (uint64_t i = start; i < end; i++) {
		uint64_t next_gene_idx = i;
		std::cout << query.back();
		for (int j = query.size() - 2; j >= 0; j--) {
			std::cout << bwt_info[next_gene_idx].gene;
			if (next_gene_idx == 0) break;
			if (query[j] != bwt_info[next_gene_idx].gene) break;
			if (j == 0) {
				next_gene_idx = nextGene(next_gene_idx);
				std::cout << "\nFOUND : " << bwt_info[next_gene_idx].left_walk;
			}
			next_gene_idx = nextGene(next_gene_idx);
		}
		std::cout << std::endl;
	}
	return false;
}

uint64_t Bwt::nextGene(const int idx) {
	uint64_t next_gene_idx;
	char gene = bwt_info[idx].gene;
	uint64_t rank =  bwt_info[idx].rank;
	switch (gene) {
	case 'A':
		next_gene_idx = p_sum[0] + rank;
		break;
	case 'C':
		next_gene_idx = p_sum[1] + rank;
		break;
	case 'G':
		next_gene_idx = p_sum[2] + rank;
		break;
	case 'T':
		next_gene_idx = p_sum[3] + rank;
		break;
	case '$':
		next_gene_idx = 0;
		break;
	default:
		assert(false);
	}

	return next_gene_idx;
}