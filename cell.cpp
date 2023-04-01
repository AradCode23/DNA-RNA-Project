#include "cell.h"

Cell::Cell(int chromosomeCount, const std::vector<Genome> &chromosomes)
        : chromosomeCount(chromosomeCount), chromosomes(chromosomes) {}

bool Cell::apoptosis() {
    for (const auto& chromosome : chromosomes) {
        int unbondedCount = 0;
        int atCount = 0;
        int cgCount = 0;

        const auto& pair = chromosome.getDna();
        for (size_t i = 0; i < pair.first.size(); ++i) {
            if ((pair.first[i] == 'A' && pair.second[i] != 'T') ||
                (pair.first[i] == 'T' && pair.second[i] != 'A') ||
                (pair.first[i] == 'C' && pair.second[i] != 'G') ||
                (pair.first[i] == 'G' && pair.second[i] != 'C')) {
                ++unbondedCount;
            }

            if ((pair.first[i] == 'A' && pair.second[i] == 'T') ||
                (pair.first[i] == 'T' && pair.second[i] == 'A')) {
                ++atCount;
            } else {
                ++cgCount;
            }
        }

        if (unbondedCount > 5 || atCount > 3 * cgCount) {
            return true;
        }
    }

    return false;
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

Cell::Cell() {}
