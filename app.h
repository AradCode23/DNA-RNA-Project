#ifndef DNA_RNA_PROJECT_APP_H
#define DNA_RNA_PROJECT_APP_H

#pragma once

#include <iostream>
#include <string>
#include "genome.h"
#include "cell.h"

class App {
public:
    App();
    void run();
private:
    void printMenu();
    void handleUserInput();
    void executeCommand(int command);
    Genome genome;
public:
    void setGenome(const Genome &genome);

    void setCell(const Cell &cell);

private:
    Cell cell;
};


#endif //DNA_RNA_PROJECT_APP_H
