#include "include/dnasequence.h"

using namespace std;

DnaSequence::DnaSequence()
{
    //ctor
}

DnaSequence::DnaSequence(std::string prebuilt)
{
    Gene g;
    unsigned int length = g.GetMaxLength();

    assert(prebuilt.length() / NUM_GENES == length);
    assert(prebuilt.length() % length == 0);

    for(int i=0; i < NUM_GENES; i++)
    {
        Gene tmp(prebuilt.substr(0, length));
        //cout << tmp.GetGene() << endl;
        genes[i] = tmp;
    }
}

DnaSequence::~DnaSequence()
{
    //dtor
}

///Picks a random gene to mutate. A mutation will occur when using this method.
void DnaSequence::Mutate()
{
    //pick a random gene to mutate
    int geneToMutate = RandomNumber::GetRandom(NUM_GENES);
    genes[geneToMutate].Mutate();
}

///Populates DNA with random values
void DnaSequence::Randomize()
{
    for(int i=0; i < NUM_GENES; i++)
    {
        Gene g;
        genes[i] = g;
    }
}

///Returns the DNA as a string
std::string DnaSequence::GetDNA()
{
    std::string dna = "";

    for(int i=0; i < NUM_GENES; i++)
    {
        dna.append(genes[i].GetGene());
    }

    return dna;
}

///Returns the length of a DNA sequence
unsigned int DnaSequence::GetMaxLength()
{
    return NUM_GENES * genes[0].GetMaxLength();
}

///Operator overload for sort()
bool DnaSequence::operator<(const DnaSequence& str) const
{
    return (FitnessScore < str.FitnessScore);
}
