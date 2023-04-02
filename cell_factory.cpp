#include "cell_factory.h"
#include "genome_factory.h"

Cell CellFactory::createObject() const {
    GenomeFactory genome_factory;
    std::vector<Genome> chromosomes;
    size_t num_chromosomes = 2; // You can set the desired number of chromosomes

    for (size_t i = 0; i < num_chromosomes; ++i) {
        chromosomes.push_back(genome_factory.createObject());
    }

    return Cell(chromosomes);
}
