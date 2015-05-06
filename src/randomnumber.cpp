#include "include/randomnumber.h"

///Seed for rand()
void RandomNumber::Init()
{
    srand (time(NULL));
}

///Returns a random value between 0 and max
int RandomNumber::GetRandom(int max)
{
    return rand() % max;
}
