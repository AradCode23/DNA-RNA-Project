#include "app.h"

App::App() {}

void App::run() {
    printMenu();
    handleUserInput();
}

void App::printMenu() {
    std::cout << "Genome and Cell Manipulation Menu:\n";
    std::cout << "1. Receive Genome Content\n";
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
            // Handle receiving genome content
            break;
        }
        case 2: {
            // Handle creating DNA from RNA
            break;
        }
        case 3: {
            // Handle subtle mutation
            break;
        }
        case 4: {
            // Handle big mutation
            break;
        }
        case 5: {
            // Handle reverse mutation
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
