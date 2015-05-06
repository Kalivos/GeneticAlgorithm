#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "include/randomnumber.h"
#include "include/dnasequence.h"

#define PERCENT_TO_SAVE .20
#define PERCENT_TO_MUTATE 0.15

class Population
{
    public:
        Population(unsigned int size);
        virtual ~Population();
        void NextGeneration();
        unsigned int GetGeneration();
        DnaSequence GetGenerationBest(unsigned int generation);
        void PrintAll();
    protected:
    private:
        double MeasureFitness(DnaSequence dna);

        unsigned int m_population_size;
        unsigned int m_generation;

        std::vector<DnaSequence> m_population;
        std::vector<DnaSequence> m_generation_best;

};

#endif // POPULATION_H
