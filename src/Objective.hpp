#ifndef __OBJECTIVE_H__
#define __OBJECTIVE_H__

#include <Solution.hpp>

namespace Rosterer
{
    class Objective
    {
    public:
        static long computeCost(const Solution& solution);
    private:
        static long minimizeSwapsDuringDay(const Solution& solution);
        static long minimizeConsecutiveWeeks(const Solution& solution);
        static long minimizeDayNightSwaps(const Solution& solution);
        static long minimizeSwapsDuringWeek(const Solution& solution);
        static long maximizeRest(const Solution& solution);
        static long maximizeFairness(const Solution& solution);
        static long minimizeDisruption(const Solution& solution);
    };
}

#endif