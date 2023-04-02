#include "genome_factory.h"
#include <random>
#include <string>

std::string randomNucleotides(size_t length) {
    std::string result(length, 'A');
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);

    const char nucleotides[] = {'A', 'T', 'C', 'G'};

    for (size_t i = 0; i < length; ++i) {
        result[i] = nucleotides[dis(gen)];
    }

    return result;
}

Genome GenomeFactory::createObject() const {
    size_t length = 10; // You can set the desired length for the nucleotide strands
    std::string rna = randomNucleotides(length);
    std::string dna_strand1 = randomNucleotides(length);
    std::string dna_strand2 = randomNucleotides(length);
    auto dna = std::make_pair(dna_strand1, dna_strand2);
    return Genome(rna, dna);
}
