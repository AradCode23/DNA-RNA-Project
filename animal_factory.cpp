#include "animal_factory.h"
#include "cell_factory.h"

Animal AnimalFactory::createObject() const {
    CellFactory cellFactory;
    std::vector<Cell> chromosomes;

    int chromosomeCount = std::rand() % 10 + 1; // Generate a random number of chromosomes between 1 and 10

    for (int i = 0; i < chromosomeCount; ++i) {
        chromosomes.push_back(cellFactory.createObject());
    }

    return Animal(chromosomes);
}
