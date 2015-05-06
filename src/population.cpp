#include "include/population.h"

using namespace std;

Population::Population(unsigned int size)
{
    //ctor
    m_population_size = size;
    m_generation = 0;

    RandomNumber::Init();

    for (unsigned int i=0; i < size; i++)
    {
        //create a new random dna sequence
        DnaSequence dna;
        dna.Randomize();

        m_population.push_back(dna);
    }

    //Evaluate fitness

    for(std::vector<DnaSequence>::iterator it=m_population.begin(); it < m_population.end(); it++)
    {
        (*it).FitnessScore = MeasureFitness(*it);
    }

    //Sort child population by fitness score
    std::sort( m_population.begin(), m_population.end() );

    m_generation_best.push_back(m_population.front());
}

Population::~Population()
{
    //dtor
}

///Advances the population to the next generation
///This does mutation, crossover, favors elite DNA
///Also performs fitness
void Population::NextGeneration()
{
    //add to the generation counter
    m_generation++;

    //child population will become the new population
    std::vector<DnaSequence> child_population;

    //we need to flip the population so that pop is looking at the head
    std::reverse(m_population.begin(), m_population.end());

    //we'll use iterators multiple times, so we'll just declare this here
    std::vector<DnaSequence>::iterator it;

    //Elitist group
    DnaSequence last;
    for(int i=0; i < m_population_size * PERCENT_TO_SAVE; i++)
    {
        child_population.push_back(m_population.back());

        //Crossovers
        if(i > 0)
        {
            int length = last.GetMaxLength();
            int r = RandomNumber::GetRandom(length);

            DnaSequence dna1(last.GetDNA().substr(0, r).append(m_population.back().GetDNA().substr(r, length-r+1)));
            DnaSequence dna2(m_population.back().GetDNA().substr(0, r).append(last.GetDNA().substr(r, length-r+1)));

            child_population.push_back(dna1);
            child_population.push_back(dna2);
        }

        last = m_population.back();
        m_population.pop_back();
    }

    //Mutations
    for(int i=0; i < m_population_size * PERCENT_TO_SAVE; i++)
    {
        assert(PERCENT_TO_MUTATE <= 1 && PERCENT_TO_MUTATE >= 0);

        if(RandomNumber::GetRandom(100) <= 100*PERCENT_TO_MUTATE)
        {
            m_population[i].Mutate();
            child_population.push_back(m_population[i]);
        }
    }

    //Fill in remaining spots with random DNA
    while(child_population.size() < m_population_size)
    {
        DnaSequence dna;
        dna.Randomize();
        child_population.push_back(dna);
    }

    //Evaluate fitness
    for(it=child_population.begin(); it < child_population.end(); it++)
    {
        (*it).FitnessScore = MeasureFitness(*it);
    }

    //Sort child population by fitness score
    std::sort( child_population.begin(), child_population.end() );

    m_population = child_population;

    //add the best of the generation to the list
    m_generation_best.push_back(child_population.front());

}

///Returns the current generation number
unsigned int Population::GetGeneration()
{
    return m_generation;
}

///Returns the best DNA from a given generation
DnaSequence Population::GetGenerationBest(unsigned int generation)
{
    if(generation > m_generation)
    {
        throw std::out_of_range("Generation out of range");
    }

    return m_generation_best[generation];
}

///Evaluates a DNA sequence and returns a score. Lowers numbers are more fit.
double Population::MeasureFitness(DnaSequence dna)
{
    double errors = 0;
    std::string sequence = dna.GetDNA();

    //TODO: change this method to whatever you want
    //In this example, we are trying to achieve a string of all 0's
    for(unsigned int i=0; i < sequence.length(); i++)
    {
        if(sequence[i] == '1')
        {
            errors++;
        }
    }

    return errors;
}

///cout all DNA in current population
void Population::PrintAll()
{
    for(std::vector<DnaSequence>::iterator it=m_population.begin(); it < m_population.end(); it++)
    {
        cout << (*it).FitnessScore << ": " << (*it).GetDNA() << endl;
    }
}
