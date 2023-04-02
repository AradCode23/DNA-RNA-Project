#include "app.h"
#include "genome_factory.h"
#include "cell_factory.h"
#include "animal_factory.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>




void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void wait(int seconds) {
    std::cout << "Screen will refresh in " << seconds <<  " seconds!\n";
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}


App::App() : animal(std::vector<Cell>{}) {}

void App::run() {

    std::srand(static_cast<unsigned>(std::time(0))); // Seed random number generator

    GenomeFactory genome_factory;
    CellFactory cell_factory;
    AnimalFactory animal_factory;

    setGenome(genome_factory.createObject());
    setCell(cell_factory.createObject());
    setAnimal(animal_factory.createObject());

    printMainMenu();
    handleUserInput();
}

void App::printMainMenu() {
    std::cout << "Main Menu:\n";
    std::cout << "1. Cell\n";
    std::cout << "2. Genome\n";
    std::cout << "3. Animal\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter the number corresponding to the class you want to work with: ";
}

void App::printSubMenu(const std::string &menuTitle) {
    clearScreen();
    std::cout << menuTitle << " Menu:\n";

    // Show menu options based on the menuTitle
    if (menuTitle == "Cell") {
        std::cout << "1. Create a Cell\n";
        std::cout << "2. Perform apoptosis\n";
        std::cout << "3. Perform subtle mutation\n";
        std::cout << "4. Perform big mutation\n";
        std::cout << "5. Perform reverse mutation\n";
    } else if (menuTitle == "Genome") {
        std::cout << "1. Create a Genome\n";
        std::cout << "2. Create DNA from RNA\n";
        std::cout << "3. Perform subtle mutation\n";
        std::cout << "4. Perform big mutation\n";
        std::cout << "5. Perform reverse mutation\n";
    } else if (menuTitle == "Animal") {
        std::cout << "1. Create an Animal\n";
        std::cout << "2. Calculate genetic distance between two animals\n";
        std::cout << "3. Check if two animals are of the same species\n";
        std::cout << "4. Perform asexual reproduction\n";
        std::cout << "5. Perform sexual reproduction\n";
    }

    std::cout << "0. Back to main menu\n";
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
        printMainMenu();
    }
}

void App::executeCommand(int command) {
    switch (command) {
        case 1: {
            handleCellMenu();
            break;
        }
        case 2: {
            handleGenomeMenu();
            break;
        }
        case 3: {
            handleAnimalMenu();
            break;
        }
        default: {
            std::cout << "Invalid command. Please try again.\n";
        }
    }
    clearScreen();
}

void App::handleCellMenu() {
    int command;
    while (true) {
        clearScreen();
        printSubMenu("Cell");
        std::cin >> command;
        if (command == 0) {
            break;
        }

        switch (command) {
            case 1: {
                cell.display();
                break;
            }
            case 2: {
                std::string S1;
                int n;
                std::string S2;
                int m;
                std::cout << "Enter S1, n, S2, m (with spaces): ";
                std::cin >> S1 >> n >> S2 >> m;
                cell.bigMutation(S1, n, S2, m);
                std::cout << "Mutation applied." << std::endl;
                break;
            }
            case 3: {
                char n1, n2;
                int n, m;
                std::cout << "Enter n1, n2, n, m (with spaces): ";
                std::cin >> n1 >> n2 >> n >> m;
                cell.subtleMutation(n1, n2, n, m);
                std::cout << "Mutation applied." << std::endl;
                break;
            }
            case 4: {
                std::string S1;
                int n;
                std::cout << "Enter S1 and n (with space): ";
                std::cin >> S1 >> n;
                cell.reverseMutation(S1, n);
                std::cout << "Mutation applied." << std::endl;
                break;
            }
            case 5: {
                int n;
                std::cout << "Enter n: ";
                std::cin >> n;
                auto palindromes = cell.findComplementPalindromes(n);
                std::cout << "Complement palindromes: " << std::endl;
                for (const auto &palindrome : palindromes) {
                    std::cout << palindrome << std::endl;
                }
                break;
            }
            case 6: {
                if (cell.shouldApoptose()) {
                    std::cout << "Apoptosis applied." << std::endl;
                } else {
                    std::cout << "Apoptosis condition not met." << std::endl;
                }
                break;
            }
            default: {
                std::cout << "Invalid command. Please try again.\n";
            }
        }

        wait(5);
    }
}

void App::handleGenomeMenu() {
    int command;
    while (true) {
        clearScreen();
        printSubMenu("Genome");
        std::cin >> command;
        if (command == 0) {
            break;
        }

        switch (command) {
            case 1: {
                genome.display();
                break;
            }
            case 2: {
                genome.createDnaFromRna();
                std::cout << "DNA created from RNA." << std::endl;
                break;
            }
            case 3: {
                char n1, n2;
                int n;
                std::cout << "Enter n1, n2, n (with spaces): ";
                std::cin >> n1 >> n2 >> n;
                genome.subtleMutation(n1, n2, n);
                std::cout << "Mutation applied." << std::endl;
                break;
            }
            case 4: {
                std::string s1, s2;
                std::cout << "Enter s1 and s2 (with space): ";
                std::cin >> s1 >> s2;
                genome.bigMutation(s1, s2);
                std::cout << "Mutation applied." << std::endl;
                break;
            }
            case 5: {
                std::string s1;
                std::cout << "Enter s1: ";
                std::cin >> s1;
                genome.reverseMutation(s1);
                std::cout << "Mutation applied." << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid command. Please try again.\n";
            }
        }
        wait(5);
    }
}

void App::handleAnimalMenu() {
    int command;
    while (true) {
        clearScreen();
        printSubMenu("Animal");
        std::cin >> command;
        if (command == 0) {
            break;
        }

        switch (command) {
            case 1: {
                std::cout << "Displaying animal content:\n";
                animal.display();
                break;
            }
            case 2: {
                std::cout << "Performing asexual reproduction:\n";
                Animal offspring = animal.asexualReproduction();
                std::cout << "Offspring animal content:\n";
                offspring.display();
                break;
            }
            case 3: {
                std::cout << "Creating a new animal using AnimalFactory for comparison...\n";
                AnimalFactory factory;
                Animal otherAnimal = factory.createObject();
                std::cout << "Created animal content:\n";
                otherAnimal.display();
                double distance = animal.geneticDistance(otherAnimal);
                std::cout << "Genetic distance between the two animals: " << distance << "%\n";
                break;
            }
            case 4: {
                std::cout << "Creating a new animal using AnimalFactory for reproduction...\n";
                AnimalFactory factory;
                Animal otherAnimal = factory.createObject();
                std::cout << "Created animal content:\n";
                otherAnimal.display();
                Animal offspring = animal + otherAnimal;
                std::cout << "Offspring animal content:\n";
                offspring.display();
                break;
            }
            case 0: {
                break;
            }
            default: {
                std::cout << "Invalid command. Please try again.\n";
            }
        }

        wait(5);
    }
    clearScreen();
}

void App::setGenome(const Genome &genome) {
    App::genome = genome;
}

void App::setCell(const Cell &cell) {
    App::cell = cell;
}

void App::setAnimal(const Animal &animal) {
    App::animal = animal;
}


