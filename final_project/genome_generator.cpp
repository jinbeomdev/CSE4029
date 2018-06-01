#include "genome_generator.h"
#include "gene_generator_util.h"
#include <cstdlib>

#include <fstream>
#include <iostream>

bool GenomeGenerator::GenerateGenome() {
	std::ifstream ifs(_reference_file_name);
	std::ofstream ofs(_file_name);

	if (!ifs || !ofs) {
		std::cout << "Can't open " << _reference_file_name << " or " << _file_name << std::endl;
		return false;
	}

	int reference_length = 0;
	while (true) {
		int miss_match_idx[2];
		while (miss_match_idx[0] == miss_match_idx[1]) {
			miss_match_idx[0] = rand() % _short_read_length;
			miss_match_idx[1] = rand() % _short_read_length;
		}

		for (int i = 0; i < _short_read_length; i++) {
			char reference_gene;
			char gene;

			ifs >> reference_gene;
			gene = reference_gene;

			if (ifs.eof()) {
				std::cout << "Done generating genome" << std::endl;
				return true;
			}

			if (i == miss_match_idx[0] || i == miss_match_idx[1]) {
				while (gene == reference_gene) {
					gene = GetRandomGene();
				}
			}

			ofs << gene;
		}
	}

	ifs.close();
	ofs.close();
}
