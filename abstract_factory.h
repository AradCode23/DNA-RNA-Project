#ifndef DNA_RNA_PROJECT_GENERICFACTORY_H
#define DNA_RNA_PROJECT_GENERICFACTORY_H

template <class T>
class AbstractFactory {
public:
    virtual ~AbstractFactory() = default;
    virtual T createObject() const = 0;
};

#endif //DNA_RNA_PROJECT_GENERICFACTORY_H
