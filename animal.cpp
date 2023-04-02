#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <random>
#include "animal.h"


Animal::Animal(const std::vector<Cell>& chromosomes) : chromosomes(chromosomes) {}


// Implement Jaccard similarity approach to calculate the genetic distance
// between the chromosomes of the two animals.
double Animal::geneticDistance(const Animal& other) const {
    if (chromosomes.size() != other.chromosomes.size()) {
        throw std::invalid_argument("Animals have different numbers of chromosomes");
    }

    int intersection_count = 0;
    int union_count = 0;

    for (size_t i = 0; i < chromosomes.size(); ++i) {
        const Cell& chromosome1 = chromosomes[i];
        const Cell& chromosome2 = other.chromosomes[i];

        for (size_t j = 0; j < chromosome1.getDna().first.size(); ++j) {
            if (chromosome1.getDna().first[j] == chromosome2.getDna().first[j]) {
                intersection_count++;
            }
            if (chromosome1.getDna().first[j] != 'X' || chromosome2.getDna().first[j] != 'X') {
                union_count++;
            }
        }
    }

    if (union_count == 0) {
        return 1.0; // Both animals have no genetic content, so they are considered identical
    }

    return static_cast<double>(intersection_count) / static_cast<double>(union_count);
}

bool Animal::operator==(const Animal& other) const {
    return geneticDistance(other) > 0.7;
}

// Implement asexual reproduction by duplicating chromosomes and
// selecting half of them randomly while ensuring the genetic distance
// with the parent is more than 70 percent.
Animal Animal::asexualReproduction() const {
    std::vector<Cell> duplicated_chromosomes = chromosomes;
    duplicated_chromosomes.insert(duplicated_chromosomes.end(), chromosomes.begin(), chromosomes.end());

    std::random_device rd;
    std::mt19937 g(rd());

    Animal offspring({});

    do {
        std::vector<Cell> offspring_chromosomes = duplicated_chromosomes;
        std::shuffle(offspring_chromosomes.begin(), offspring_chromosomes.end(), g);

        offspring_chromosomes.resize(chromosomes.size());
        offspring = Animal(offspring_chromosomes);
    } while (!isValidReproduction(offspring, *this));

    return offspring;
}


// Implement sexual reproduction by performing asexual reproduction
// for both parents, then merging half of the chromosomes from each
// parent, ensuring that the genetic distance with both parents is more than 70 percent.
// If the number of chromosomes is odd, throw an exception.
Animal Animal::operator+(const Animal& other) const {
    if (chromosomes.size() != other.chromosomes.size()) {
        throw std::invalid_argument("Animals have different numbers of chromosomes");
    }

    if (chromosomes.size() % 2 != 0) {
        throw std::invalid_argument("Odd number of chromosomes, sexual reproduction not possible");
    }

    Animal offspring1 = asexualReproduction();
    Animal offspring2 = other.asexualReproduction();

    std::vector<Cell> merged_chromosomes(chromosomes.size());
    std::random_device rd;
    std::mt19937 g(rd());

    do {
        for (size_t i = 0; i < chromosomes.size() / 2; ++i) {
            merged_chromosomes[i] = offspring1.chromosomes[i];
            merged_chromosomes[i + chromosomes.size() / 2] = offspring2.chromosomes[i + chromosomes.size() / 2];
        }

        std::shuffle(merged_chromosomes.begin(), merged_chromosomes.end(), g);
    } while (!isValidReproduction(Animal(merged_chromosomes), *this) ||
             !isValidReproduction(Animal(merged_chromosomes), other));

    return Animal(merged_chromosomes);
}

// Implement apoptosis by removing chromosomes that meet apoptosis conditions.
void Animal::apoptosis() {
    chromosomes.erase(
            std::remove_if(chromosomes.begin(), chromosomes.end(),
                           [](const Cell& chromosome) { return chromosome.shouldApoptose(); }),
            chromosomes.end());
}

bool Animal::isValidReproduction(const Animal& offspring, const Animal& parent) const {
    return offspring.geneticDistance(parent) > 0.7;
}

void Animal::display() const {
    std::cout << "Animal content:" << std::endl;
    for (const auto& chromosome : chromosomes) {
        chromosome.display();
    }
}

const std::vector<Cell> &Animal::getChromosomes() const {
    return chromosomes;
}
