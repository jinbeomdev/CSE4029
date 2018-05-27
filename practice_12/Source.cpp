/*
Student ID : 201313504
Student Name : KIM JIN BEOM

Create a reference genome similar to the 1,000,000 input
sequence that we made in the last project.

Try to create a reference genome similar to the input
sequence. You can create reference genome by
changing 4-5milion genes(creating mismathces) from
my genome sequence. Look up the random pattern
(created in project 2 in slide 9) in the reference genome.
print index! At this point, implement finding a string by
allowing up two mismatches. (When cutting a my genome
to make a short read, make it repeat the length I
from any random position in my genome. Make as many
as you like at least ten times in each postion.)

Implement your code
increase n 10000 by 10 times
increase i from 5 to 30 (example i = 5, 10, 15, 20, 30)
- show the running time and compare it with the one
from trivial mapping algorithm
- show the accuracy and compare it with the one from
trivial mapping algorithm
- use graph to show your results.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

const char *reference_genome_file_name = "reference_genome.txt";
const char *my_genome_file_name = "my_genome.txt";

int main() {
	ofstream reference_genome_file(reference_genome_file_name, ofstream::out);
	ofstream my_genome_file(my_genome_file_name, ofstream::out);

	srand(time(NULL));
	for (int i = 0; i < 1000000; i++) {
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
		reference_genome_file << gene;
	}
	reference_genome_file.close();



	my_genome_file.close();
}