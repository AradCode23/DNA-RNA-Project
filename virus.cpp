#include "virus.h"
#include "cell.h"

Virus::Virus(const std::string &rna) : rna(rna) {}

Virus::Virus() {}


bool Virus::isHarmful(const Animal &animal) const {
    std::string longestCommonSubstring = "";

    // Find the longest common substring among all chromosomes
    auto chromosomes = animal.getChromosomes();
    for (size_t i = 0; i < chromosomes.size() - 1; ++i) {
        for (size_t j = i + 1; j < chromosomes.size(); ++j) {
            std::string commonSubstring = findLongestCommonSubstring(chromosomes[i].getRna(), chromosomes[j].getRna());
            if (commonSubstring.length() > longestCommonSubstring.length()) {
                longestCommonSubstring = commonSubstring;
            }
        }
    }

    if (longestCommonSubstring.length() > 0) {
        if (rna.find(longestCommonSubstring) != std::string::npos) {
            return true;
        } else {
            std::string complementLCS = complement(longestCommonSubstring);
            if (rna.find(complementLCS) != std::string::npos) {
                return true;
            }
        }
    }

    return false;
}


std::string Virus::findLongestCommonSubstring(const std::string &s1, const std::string &s2) const {
    int m = s1.length();
    int n = s2.length();
    int maxLength = 0;
    int endIndex = -1;
    std::vector<std::vector<int>> lengths(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                lengths[i][j] = lengths[i - 1][j - 1] + 1;
                if (lengths[i][j] > maxLength) {
                    maxLength = lengths[i][j];
                    endIndex = i - 1;
                }
            } else {
                lengths[i][j] = 0;
            }
        }
    }

    if (maxLength == 0) {
        return "";
    }

    return s1.substr(endIndex - maxLength + 1, maxLength);
}

void Virus::setRna(const std::string &rna) {
    Virus::rna = rna;
}
