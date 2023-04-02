#ifndef DNA_RNA_PROJECT_ANIMAL_H
#define DNA_RNA_PROJECT_ANIMAL_H

//#pragma once

#include <vector>
#include "cell.h"

class Animal : public Cell {
public:
    Animal(const std::vector<Cell>& chromosomes);

    double geneticDistance(const Animal& other) const;
    void display() const override;
    bool operator==(const Animal& other) const;
    Animal asexualReproduction() const;
    Animal operator+(const Animal& other) const;
    void apoptosis() override;

private:
    std::vector<Cell> chromosomes;
    bool isValidReproduction(const Animal& offspring, const Animal& parent) const;
};


#endif //DNA_RNA_PROJECT_ANIMAL_H
