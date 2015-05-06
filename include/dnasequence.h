#ifndef DNASEQUENCE_H
#define DNASEQUENCE_H

#include <string>
#include "include/randomnumber.h"
#include "include/gene.h"

#define NUM_GENES 20

class DnaSequence
{
    public:
        DnaSequence();
        DnaSequence(std::string prebuilt);
        void Mutate();
        void Randomize();
        unsigned int GetMaxLength();
        std::string GetDNA();

        virtual ~DnaSequence();

        double FitnessScore;

        bool operator<(const DnaSequence& str) const;
    protected:
    private:
        Gene genes[NUM_GENES];

};

#endif // DNASEQUENCE_H
