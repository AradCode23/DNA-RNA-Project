#ifndef DNA_RNA_PROJECT_APP_H
#define DNA_RNA_PROJECT_APP_H

#pragma once

#include <iostream>
#include <string>
#include "genome.h"
#include "cell.h"
#include "animal.h"

class App {
public:
    App();

    void run();

    void setGenome(const Genome &genome);

    void setCell(const Cell &cell);

    void setAnimal(const Animal &animal);


private:
    Genome genome;
    Cell cell;
    Animal animal;

    void printMainMenu();

    void printSubMenu(const std::string &menuTitle);

    void handleUserInput();

    void executeCommand(int command);

    void handleCellMenu();

    void handleGenomeMenu();

    void handleAnimalMenu();
};

#endif //DNA_RNA_PROJECT_APP_H
