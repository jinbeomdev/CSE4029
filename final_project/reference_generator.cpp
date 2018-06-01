#include "reference_generator.h"
#include "gene_generator_util.h"
#include <iostream>
#include <fstream>

bool ReferenceGenerator::GenerateReferenceGenome() {
	std::ofstream _of(_file_name);
	if (!_of) {
		std::cout << "Can't open " << _file_name << std::endl;
		return false;
	}

	for (uint64_t i = 0; i < _genome_size; i++) {
		_of << GetRandomGene();
	}

	std::cout << "Done generating reference genome" << std::endl;
	_of.close();
}
