#ifndef __SOLUTION_H__
#define __SOLUTION_H__

#include <vector>
#include <string>
#include <optional>

namespace Rosterer
{
    class Solution
    {
    public:
        Solution() {};
        Solution(std::vector<int>&& nighttimeRoster, std::vector<int>&& daytimeRoster);

        const std::vector<int>& getNighttimeRoster() const;
        const std::vector<int>& getDaytimeRoster() const;
        void setRosters(std::vector<int>&& nighttimeRoster, std::vector<int>&& daytimeRoster);
        const std::string& getID() const;
        long getCost();
    private:
        void computeID();
        void computeCost();

        std::vector<int> _nighttimeRoster;
        std::vector<int> _daytimeRoster;
        std::string _id;
        std::optional<long> _cost;
    };
}

#endif