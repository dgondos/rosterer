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

        static InitialRosterManager& instance();
        InitialRosterManager(InitialRosterManager const&) = delete;
        void operator=(InitialRosterManager const&) = delete;

        const Solution& getInitialSolution() const;
        bool isWeekend(int idxDay) const;
        bool isHolidayBLR(int idxDay) const;
        bool isHolidayNCE(int idxDay) const;
        bool isHolidaySYD(int idxDay) const;
        int getNbrDaysOptimized() const;
        int getFirstSundayIdx() const;
        const std::vector<std::string>& getAllStaff() const;
    private:
        InitialRosterManager();

        Solution _initialSolution;
        std::vector<std::vector<bool>> _calendar;
        std::vector<std::string> _staff;
        int _firstSundayIdx;
    };
}

#endif