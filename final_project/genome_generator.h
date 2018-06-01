#pragma once
#ifndef GENOME_GENERATOR_H
#define GENOME_GENERATOR_H

#include <string>

class GenomeGenerator {
private:
	std::string _reference_file_name;
	std::string _file_name;
	int _short_read_length;
public:
	GenomeGenerator() {}
	GenomeGenerator(std::string reference_file_name, std::string file_name, int short_read_length = 30) :
		_reference_file_name(reference_file_name), _file_name(file_name), _short_read_length(short_read_length) {}
	~GenomeGenerator() {}
	bool GenerateGenome();
};

#endif // !GENOME_GENERATOR_H

