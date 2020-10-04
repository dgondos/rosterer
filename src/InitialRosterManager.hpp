#ifndef __INITIAL_ROSTER_MANAGER_H__
#define __INITIAL_ROSTER_MANAGER_H__

#include <vector>
#include <string>

#include <Solution.hpp>

namespace Rosterer
{
    class InitialRosterManager
    {
    public:
        static const Solution& getInitialSolution();
        static bool isWeekend(int idxDay);
        static bool isHolidayBLR(int idxDay);
        static bool isHolidayNCE(int idxDay);
        static bool isHolidaySYD(int idxDay);
        static int getNbrDaysOptimized();
        static int getFirstSundayIdx();
    private:
        static const std::vector<std::vector<bool>>& getCalendar();
    };
}

#endif