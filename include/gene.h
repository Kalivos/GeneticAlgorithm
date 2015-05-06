#ifndef GENE_H
#define GENE_H

#include <string>
#include <iostream>
#include <assert.h>

#define GENE_LENGTH 5

class Gene
{
    public:
        Gene();
        Gene(std::string prebuilt);
        virtual ~Gene();
        std::string GetGene();
        unsigned int GetMaxLength();
        void Mutate();
    protected:
    private:
        bool gene_sequence[GENE_LENGTH];
};

#endif // GENE_H
