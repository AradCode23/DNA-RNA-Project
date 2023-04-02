#include "cell.h"
#include <iostream>
#include <algorithm>
#include <utility>

Cell::Cell() {}

Cell::Cell(const std::vector<Genome> &chromosomes)
        : chromosomeCount(chromosomeCount), chromosomes(chromosomes) {
    chromosomeCount = chromosomes.size();
}


bool Cell::shouldApoptose() const {
    return std::any_of(chromosomes.begin(), chromosomes.end(), [](const Genome &chromosome) {
        std::size_t noBondCount = 0;
        std::size_t atPairCount = 0;
        std::size_t cgPairCount = 0;

        std::pair<std::string, std::string> dna = chromosome.getDna();
        std::size_t dnaSize = dna.first.size();

        for (std::size_t i = 0; i < dnaSize; i++) {
            char firstStrandNucleotide = dna.first[i];
            char secondStrandNucleotide = dna.second[i];

            if ((firstStrandNucleotide == 'A' && secondStrandNucleotide == 'T') ||
                (firstStrandNucleotide == 'T' && secondStrandNucleotide == 'A')) {
                atPairCount++;
            } else if ((firstStrandNucleotide == 'C' && secondStrandNucleotide == 'G') ||
                       (firstStrandNucleotide == 'G' && secondStrandNucleotide == 'C')) {
                cgPairCount++;
            } else {
                noBondCount++;
            }
        }

        return noBondCount > 5 || atPairCount > 3 * cgPairCount;
    });
}

void Cell::apoptosis() {
    auto newEnd = std::remove_if(chromosomes.begin(), chromosomes.end(), [this](const Genome &chromosome) {
        return shouldApoptose();
    });

    chromosomes.erase(newEnd, chromosomes.end());
}


void Cell::bigMutation(const std::string &S1, int n, const std::string &S2, int m)
{
    if (n >= 0 && n < chromosomeCount && m >= 0 && m < chromosomeCount)
    {
        chromosomes[n].bigMutation(S1, S2);
        chromosomes[m].bigMutation(S2, S1);
    }
}

void Cell::subtleMutation(char n1, char n2, int n, int m)
{
    if (n >= 0 && n < chromosomeCount)
    {
        chromosomes[n].subtleMutation(n1, n2, m);
    }
}

void Cell::reverseMutation(const std::string &S1, int n)
{
    if (n >= 0 && n < chromosomeCount)
    {
        chromosomes[n].reverseMutation(S1);
    }
}

std::vector<std::string> Cell::findComplementPalindromes(int n)
{
    std::vector<std::string> result;

    if (n >= 0 && n < chromosomeCount)
    {
        const auto &pair = chromosomes[n].getDna();

        for (size_t i = 0; i < pair.first.size(); ++i)
        {
            for (size_t j = i + 2; j < pair.first.size(); ++j)
            {
                bool isPalindrome = true;
                for (size_t k = i; k <= j; ++k)
                {
                    if (pair.first[k] != complement(pair.second[j - k]))
                    {
                        isPalindrome = false;
                        break;
                    }
                }
                if (isPalindrome)
                {
                    result.push_back(pair.first.substr(i, j - i + 1));
                }
            }
        }
    }

    return result;
}

void Cell::display() const {
    std::cout << "Cell content:" << std::endl;
    for (const auto& chromosome : chromosomes) {
        chromosome.display();
    }
}