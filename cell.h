#ifndef DNA_RNA_PROJECT_CELL_H
#define DNA_RNA_PROJECT_CELL_H

#include "genome.h"
#include "dna_utils.h"

class Cell : public Genome
{
public:
    Cell(const std::vector<Genome> &chromosomes);

    Cell();

    bool apoptosis();
    void bigMutation(const std::string &S1, int n, const std::string &S2, int m);
    void subtleMutation(char n1, char n2, int n, int m);
    void reverseMutation(const std::string &S1, int n);
    std::vector<std::string> findComplementPalindromes(int n);

private:
    int chromosomeCount;
    std::vector<Genome> chromosomes;
};


#endif //DNA_RNA_PROJECT_CELL_H
