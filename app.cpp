#include "app.h"
#include "genome_factory.h"
#include "cell_factory.h"
#include <iostream>
#include <string>

App::App() {}

void App::run() {
    GenomeFactory genome_factory;
    CellFactory cell_factory;

    setGenome(genome_factory.createObject());
    setCell(cell_factory.createObject());

    printMenu();
    handleUserInput();
}

void App::printMenu() {
    std::cout << "Genome and Cell Manipulation Menu:\n";
    std::cout << "1. Display Genome Content\n";
    std::cout << "2. Create DNA from RNA\n";
    std::cout << "3. Subtle Mutation\n";
    std::cout << "4. Big Mutation\n";
    std::cout << "5. Reverse Mutation\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter the number corresponding to the action you want to perform: ";
}

void App::handleUserInput() {
    int command;
    while (true) {
        std::cin >> command;
        if (command == 0) {
            break;
        }
        executeCommand(command);
        printMenu();
    }
}

void App::executeCommand(int command) {
    switch (command) {
        case 1: {
            std::cout << "RNA:\n" << genome.getRna() << "\n";
            std::cout << "DNA:\n" << genome.getDna().first << " " << genome.getDna().second << "\n";
            break;
        }
        case 2: {
            genome.createDnaFromRna();
            std::cout << "DNA created from RNA:\n" << genome.getDna().first << "\n" << genome.getDna().second << "\n";
            break;
        }
        case 3: {
            char n1, n2;
            int n;
            std::cout << "Enter the nucleotide to replace, the replacement nucleotide, and the number of replacements: ";
            std::cin >> n1 >> n2 >> n;
            genome.subtleMutation(n1, n2, n);
            std::cout << "Subtle mutation applied.\n";
            break;
        }
        case 4: {
            std::string s1, s2;
            std::cout << "Enter the substring to replace and the replacement substring: ";
            std::cin >> s1 >> s2;
            genome.bigMutation(s1, s2);
            std::cout << "Big mutation applied.\n";
            break;
        }
        case 5: {
            std::string s1;
            std::cout << "Enter the substring to reverse: ";
            std::cin >> s1;
            genome.reverseMutation(s1);
            std::cout << "Reverse mutation applied.\n";
            break;
        }
        default: {
            std::cout << "Invalid command. Please try again.\n";
        }
    }
}

void App::setGenome(const Genome &genome) {
    App::genome = genome;
}

void App::setCell(const Cell &cell) {
    App::cell = cell;
}
