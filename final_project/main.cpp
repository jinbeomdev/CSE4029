#include "reference_generator.h"
#include "genome_generator.h"
#include "bwt.h"
#include <ctime>
#include <string>
#include <fstream>
#include <iostream>

int main() {
	std::string reference_name = "r.txt";
	//std::string gene_name = "g.txt";

	//srand(time(NULL));
	//ReferenceGenerator r(reference_name, 10);
	//r.GenerateReferenceGenome();
	//GenomeGenerator g(reference_name, gene_name, 5);
	//g.GenerateGenome();

	//std::ifstream ifs(reference_name);

	//if (!ifs) {
	//	std::cout << "Can't open " << reference_name << " file" << std::endl;
	//	return 1;
	//}
	//Bwt bwt;
	//bwt.GenerateBwtInfo(ifs);
	//bwt.PrintBwtInfo();
	//bwt.SearchQuery(std::string("AG"));

	system("pause");

	return 0;
}