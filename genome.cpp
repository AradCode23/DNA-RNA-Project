#include "genome.h"
#include "dna_utils.h"
#include <iostream>
#include <algorithm>

Genome::Genome() {}

void Genome::receiveContent(const std::string &rna, const std::pair<std::string, std::string> &dna)
{
    this->rna = rna;
    this->dna = dna;
}

void Genome::createDNAfromRNA() {
    // Convert RNA to DNA (using T instead of U)
    std::string dna_strand = rna;
    for (char& base : dna_strand) {
        if (base == 'U') {
            base = 'T';
        }
    }

    // Generate the complementary DNA strand
    std::string dna_complement;
    for (const char base : dna_strand) {
        dna_complement.push_back(complement(base));
    }

    // Set the DNA field
    dna = std::make_pair(dna_strand, dna_complement);

    // Print the DNA
    std::cout << dna.first << " " << dna.second << std::endl;
}


void Genome::subtleMutation(char n1, char n2, int n) {
    int count = 0;
    for (size_t i = 0; i < rna.size() && count < n; ++i) {
        if (rna[i] == n1) {
            rna[i] = n2;
            ++count;
        }
    }

    count = 0;
    for (size_t i = 0; i < dna.first.size() && count < n; ++i) {
        if (dna.first[i] == n1) {
            dna.first[i] = n2;
            ++count;
        }
    }
    count = 0;
    for (size_t i = 0; i < dna.second.size() && count < n; ++i) {
        if (dna.second[i] == complement(n1)) {
            dna.second[i] = complement(n2);
            ++count;
        }
    }
}

void Genome::bigMutation(const std::string& s1, const std::string& s2) {
    auto s1Complement = std::string(s1.rbegin(), s1.rend());
    for (auto& c : s1Complement) {
        c = complement(c);
    }

    auto pos = rna.find(s1);
    if (pos != std::string::npos) {
        rna.replace(pos, s1.length(), s2);
    }

    pos = dna.first.find(s1);
    if (pos != std::string::npos) {
        dna.first.replace(pos, s1.length(), s2);
    }
    pos = dna.second.find(s1Complement);
    if (pos != std::string::npos) {
        dna.second.replace(pos, s1Complement.length(), s1);
    }
}

void Genome::reverseMutation(const std::string& s1) {
    std::string s1Reversed(s1.rbegin(), s1.rend());
    std::string s1ComplementReversed = s1Reversed;
    for (auto& c : s1ComplementReversed) {
        c = complement(c);
    }

    size_t pos = rna.find(s1);
    while (pos != std::string::npos) {
        rna.replace(pos, s1.length(), s1Reversed);
        pos = rna.find(s1, pos + s1Reversed.length());
    }

    pos = dna.first.find(s1);
    while (pos != std::string::npos) {
        dna.first.replace(pos, s1.length(), s1Reversed);
        pos = dna.first.find(s1, pos + s1Reversed.length());
    }
    pos = dna.second.find(s1ComplementReversed);
    while (pos != std::string::npos) {
        dna.second.replace(pos, s1ComplementReversed.length(), s1ComplementReversed);
        pos = dna.second.find(s1ComplementReversed, pos + s1ComplementReversed.length());
    }
}

const std::string &Genome::getRna() const {
    return rna;
}

const std::pair<std::string, std::string> &Genome::getDna() const {
    return dna;
}
