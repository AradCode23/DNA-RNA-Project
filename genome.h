#ifndef DNA_RNA_PROJECT_GENOME_H
#define DNA_RNA_PROJECT_GENOME_H

#include <string>
#include <vector>
#include "dna_utils.h"

class Genome {
public:
    Genome();

    Genome(const std::string &rna, const std::pair<std::string, std::string> &dna);

    void receiveContent(const std::string& rna, const std::pair<std::string, std::string>& dna);
    void createDnaFromRna();
    void subtleMutation(char n1, char n2, int n);
    void bigMutation(const std::string& s1, const std::string& s2);
    void reverseMutation(const std::string& s1);
    virtual void display() const;
    const std::string &getRna() const;
    const std::pair<std::string, std::string> &getDna() const;

private:
    std::string rna;
    std::pair<std::string, std::string> dna;
};

#endif //DNA_RNA_PROJECT_GENOME_H
