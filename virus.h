//
// Created by Dear User on 4/2/2023.
//

#ifndef DNA_RNA_PROJECT_VIRUS_H
#define DNA_RNA_PROJECT_VIRUS_H


#pragma once

#include <string>
#include "animal.h"
#include "dna_utils.h"

class Animal;  // Forward declaration

class Virus {
public:
    explicit Virus(const std::string &rna);

    Virus();

    bool isHarmful(const Animal &animal) const;

    void setRna(const std::string &rna);


private:
    std::string rna;
    friend class Animal;
    std::string findLongestCommonSubstring(const std::string &s1, const std::string &s2) const;
};



#endif //DNA_RNA_PROJECT_VIRUS_H
