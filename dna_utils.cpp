#include <stdexcept>
#include "dna_utils.h"

char complement(char base) {
    switch (base) {
        case 'A': return 'T';
        case 'T': return 'A';
        case 'C': return 'G';
        case 'G': return 'C';
        default:  throw std::invalid_argument("Invalid base");
    }
}

std::string complement(const std::string& base) {
    std::string res;
    res.reserve(base.size());

    for (auto nucleotide : base) {
        res.push_back(complement(nucleotide));
    }

    return res;
}
