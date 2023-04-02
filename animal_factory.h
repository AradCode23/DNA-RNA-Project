#ifndef DNA_RNA_PROJECT_ANIMALFACTORY_H
#define DNA_RNA_PROJECT_ANIMALFACTORY_H

#include "abstract_factory.h"
#include "animal.h"

class AnimalFactory : public AbstractFactory<Animal> {
public:
    Animal createObject() const override;
};


#endif //DNA_RNA_PROJECT_ANIMALFACTORY_H
