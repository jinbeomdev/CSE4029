#pragma once
#ifndef REFERENCE_GENERATOR_H
#define REFERENCE_GENERATOR_H

#include <string>

class ReferenceGenerator {
private:
	std::string _file_name;
	uint64_t _genome_size;
public:
	ReferenceGenerator() {}
	ReferenceGenerator(const std::string file_name, const uint64_t genome_size) :
		_file_name(file_name),
		_genome_size(genome_size) {};
	~ReferenceGenerator() {}
	bool GenerateReferenceGenome();
};

#endif // REFERENCE_GENERATOR_H
