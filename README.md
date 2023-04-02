# Genome and Cell Manipulation
This project provides an application for simulating genome and cell manipulation, including various operations on genomes, cells, and animals. The application is designed as a user-friendly console application with a clear menu system that allows users to perform various actions.

---

## Features
- Receive genome content
- Create DNA from RNA
- Perform subtle and big mutations
- Reverse mutations
- Perform asexual reproduction in animals
- Perform sexual reproduction in animals
- Calculate genetic distance between animals
- Determine if two animals are of the same species
- Perform apoptosis on cells

---

## Classes
The project includes several classes to model the problem domain:

> Genome: Represents a genome with RNA and DNA sequences and provides methods for various manipulations

> Cell: Inherits from Genome and represents a cell with multiple chromosomes

> Animal: Inherits from Cell and represents an animal with multiple cells and methods for asexual and sexual reproduction

> App: Manages the console application and user interaction

> Factory classes: Create instances of Genome, Cell, and Animal using randomization

---

## Usage
> Compile and build the project using a C++ compiler (e.g., g++, clang)
Run the compiled executable
Follow the prompts in the console application to perform various operations on genomes, cells, and animals


### Example
```
Genome and Cell Manipulation Menu:
1. Cell
2. Genome
3. Animal
0. Exit
Enter the number corresponding to the action you want to perform: 1

Cell Menu:
1. Perform apoptosis
2. Subtle mutation
...
0. Back to main menu
Enter the number corresponding to the action you want to perform: 1
```


## Dependencies
C++17 or later

---

## Contributing
Feel free to submit pull requests or open issues if you find any bugs or have suggestions for improvements. All contributions are welcome.
