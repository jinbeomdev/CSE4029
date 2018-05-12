/*
Student ID : 2013113504
Student Name : KIM JIN BEOM

Project preparation1

DNA sequence is composed of four letters A/C/G/T.
Let¡¯s use the algorithms that we have learned at lecture for DNA sequence matching.
randomly generate text of length n=1,000,000 and save it into input.txt.
Submit the input.txt file and the code
*/
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

const int kFileLength = 1000000;
const char *fake_gene_file_name = "input.txt";

int main() {
	srand(time(NULL));

	ofstream fake_gene_file;
	fake_gene_file.open(fake_gene_file_name);

	for (int i = 0; i < kFileLength; i++) {
		char gene;
		switch (rand() % 4)
		{
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

		fake_gene_file << gene;
	}

	fake_gene_file.close();

	return 0;
}