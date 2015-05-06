#include <iostream>

#include "include/population.h"

#define MAX_GENERATIONS 10000
#define DEFAULT_POPULATION_SIZE 100

using namespace std;

int main(int argc, char *argv[])
{
    unsigned int popSize = 0;

    if(argc == 1)
    {
        popSize = DEFAULT_POPULATION_SIZE;
    }
    else
    {
        popSize = atoi(argv[1]);
    }

    cout << "Creating population of size " << popSize << endl;
    Population p(popSize);

    for (int generation = 0;  generation < MAX_GENERATIONS && p.GetGenerationBest(generation).FitnessScore != 0; generation = p.GetGeneration())
    {
        cout << "Generation " << generation << " best: " << p.GetGenerationBest(generation).FitnessScore << endl;
        p.NextGeneration();
        //cout << "DNA: " << p.GetGenerationBest(generation).GetDNA() << endl;
    }

    cout << "Overall Best in " << p.GetGeneration() << " generations: " << p.GetGenerationBest(p.GetGeneration()).GetDNA() << endl;
    return 0;
}
