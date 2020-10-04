#ifndef __MOVE_GENERATOR_H__
#define __MOVE_GENERATOR_H__

#include <Solution.hpp>

#include <vector>

namespace Rosterer
{
    class MoveGenerator
    {
    public:
        static std::vector<Solution> generateNeighborhood(const Solution& startSolution);
    private:
        static void swapWeeks(std::vector<int>& roster, int week1Offs, int week2Offs, int initSkip);
        static void swapDays(std::vector<int>& roster, int dayOffs, int week1Offs, int week2Offs, int initSkip);
    };
}

#endif