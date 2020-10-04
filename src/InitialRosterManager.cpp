#include <InitialRosterManager.hpp>

using namespace Rosterer;

InitialRosterManager& InitialRosterManager::instance() {
    static InitialRosterManager instance;
    return instance;
}

InitialRosterManager::InitialRosterManager() {
    _staff = {"Ahmed", "Daniel G", "Hari", "Jeremy", "Mohamed", "Nagesha", "Rahul", "Roniit", "Shithali", "Thilo", "Valentin", "Vijay"};
    _initialSolution = Solution({11, 11, 11, 11, 11, 11, 11, 8, 8, 8, 8, 8, 8, 8, 10, 10, 10, 10, 10, 10, 10, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 9, 9, 9, 9, 9, 9, 9, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 8, 8, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7, 9, 9, 9, 9, 9, 9, 9, 11, 11, 11, 11, 11, 11, 11, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 4, 4, 10, 10, 10, 10, 10, 10, 10, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 8, 8, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7, 9, 9, 9, 9, 9, 9, 9, 11, 11, 11, 11, 11, 11, 11, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 6, 6, 6, 6, 6, 6, 6, 10, 10, 10, 10, 10, 10, 10},
    {11, 11, 11, 11, 11, 11, 11, 8, 8, 8, 8, 8, 8, 8, 10, 10, 10, 10, 10, 10, 10, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 9, 9, 9, 9, 9, 9, 9, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 8, 8, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7, 9, 9, 9, 9, 9, 9, 9, 11, 11, 11, 11, 11, 11, 11, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 4, 4, 10, 10, 10, 10, 10, 10, 10, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 8, 8, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7, 9, 9, 9, 9, 9, 9, 9, 11, 11, 11, 11, 11, 11, 11, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 6, 6, 6, 6, 6, 6, 6, 10, 10, 10, 10, 10, 10, 10});

    _calendar = std::vector<std::vector<bool>>{ { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, true }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, true }, { true, false, false, false }, { true, false, false, false }, { false, false, true, true }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, true }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, true }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { true, false, false, false }, { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, true }, { true, false, false, false }, { true, false, false, false }, { false, false, false, true }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, true }, { true, false, false, false }, { true, false, false, false } };

    _firstSundayIdx = -1;
    if (isWeekend(0)) {
        if (isWeekend(1)) { // we're starting on saturday
            _firstSundayIdx = 1;
        }
        else { // we're starting on sunday
            _firstSundayIdx = 0;
        }
    }
    else {
        for (int idx = 0; idx < getNbrDaysOptimized(); idx++) {
            if (isWeekend(idx)) { // found the first saturday
                _firstSundayIdx = idx + 1;
                break;
            }
        }
    }
}

const Solution& InitialRosterManager::getInitialSolution() const {
    return _initialSolution;
}

bool InitialRosterManager::isWeekend(int idxDay) const {
    return _calendar.at(idxDay).at(0);
}

bool InitialRosterManager::isHolidayBLR(int idxDay) const {
    return _calendar.at(idxDay).at(1);
}

bool InitialRosterManager::isHolidayNCE(int idxDay) const {
    return _calendar.at(idxDay).at(2);
}

bool InitialRosterManager::isHolidaySYD(int idxDay) const {
    return _calendar.at(idxDay).at(3);
}

int InitialRosterManager::getNbrDaysOptimized() const {
    return _calendar.size();
}

int InitialRosterManager::getFirstSundayIdx() const {
    return _firstSundayIdx;
}

const std::vector<std::string>& InitialRosterManager::getAllStaff() const {
    return _staff;
}