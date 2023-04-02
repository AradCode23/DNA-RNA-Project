#ifndef DNA_RNA_PROJECT_GENOME_FACTORY_H
#define DNA_RNA_PROJECT_GENOME_FACTORY_H

#include "abstract_factory.h"
#include "genome.h"

class GenomeFactory : public AbstractFactory<Genome> {
public:
    virtual Genome createObject() const override;
};

#endif //DNA_RNA_PROJECT_GENOME_FACTORY_H
