#include "include/gene.h"
#include "include/randomnumber.h"

using namespace std;

Gene::Gene()
{
    //ctor
    for (int i=0; i < GENE_LENGTH; i++)
    {
        gene_sequence[i] = RandomNumber::GetRandom(2);
    }
}

Gene::Gene(string prebuilt)
{
    //ctor
    assert(prebuilt.length() == GENE_LENGTH);

    for (int i=0; i < GENE_LENGTH; i++)
    {
        bool tmp = prebuilt[i] == '1';
        gene_sequence[i] = tmp;
    }
}

Gene::~Gene()
{
    //dtor
}

///returns the gene as a binary string
string Gene::GetGene()
{
    string builder = "";

    for(int i=0; i < GENE_LENGTH; i++)
    {
        gene_sequence[i] == 1 ? builder.append("1") : builder.append("0");
    }

    return builder;
}

///returns the length of a gene
unsigned int Gene::GetMaxLength()
{
    return GENE_LENGTH;
}

///Changes the value at a random position to opposite of what it currently is
void Gene::Mutate()
{
    unsigned int position = RandomNumber::GetRandom(GENE_LENGTH);
    gene_sequence[position] = !gene_sequence[position];
}
