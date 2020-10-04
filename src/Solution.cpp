#include <Solution.hpp>

#include <Objective.hpp>

#include <sstream>
#include <iterator>

using namespace Rosterer;

Solution::Solution(std::vector<int>&& nighttimeRoster, std::vector<int>&& daytimeRoster) {
    _nighttimeRoster.swap(nighttimeRoster);
    _daytimeRoster.swap(daytimeRoster);
    computeID();
}

const std::vector<int>& Solution::getNighttimeRoster() const {
    return _nighttimeRoster;
}

const std::vector<int>& Solution::getDaytimeRoster() const {
    return _daytimeRoster;
}

const std::string& Solution::getID() const {
    return _id;
}

void Solution::computeID() {
    std::stringstream dayString;
    std::copy(_daytimeRoster.begin(), _daytimeRoster.end(), std::ostream_iterator<int>(dayString, " "));
    std::stringstream nightString;
    std::copy(_nighttimeRoster.begin(), _nighttimeRoster.end(), std::ostream_iterator<int>(nightString, " "));
    _id = dayString.str() + nightString.str();
}

long Solution::getCost() {
    if (!_cost.has_value()) {
        computeCost();
    }
    return _cost.value();
}

void Solution::computeCost() {
    _cost = Objective::computeCost(*this);
}