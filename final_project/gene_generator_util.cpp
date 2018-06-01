#include "gene_generator_util.h"
#include <cstdlib>
#include <cassert>

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
