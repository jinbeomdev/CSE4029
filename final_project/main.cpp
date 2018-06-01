#include "reference_generator.h"
#include "genome_generator.h"
#include <ctime>
#include <string>

int main() {
	std::string reference_name = "r.txt";
	std::string gene_name = "g.txt";

	srand(time(NULL));
	ReferenceGenerator r(reference_name, 10);
	r.GenerateReferenceGenome();
	GenomeGenerator g(reference_name, gene_name, 5);
	g.GenerateGenome();

	system("pause");

	return 0;
}