#ifndef DNA_RNA_PROJECT_CELL_FACTORY_H
#define DNA_RNA_PROJECT_CELL_FACTORY_H

#include "abstract_factory.h"
#include "cell.h"

class CellFactory : public AbstractFactory<Cell> {
public:
    virtual Cell createObject() const override;
};

#endif //DNA_RNA_PROJECT_CELL_FACTORY_H
