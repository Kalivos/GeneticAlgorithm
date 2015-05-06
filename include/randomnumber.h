#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class RandomNumber
{
    public:
        static void Init();
        static int GetRandom(int max);
};

#endif // RANDOMNUMBER_H
