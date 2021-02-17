#include <InitialRosterManager.hpp>
#include <csv.h>

#include <Staff.hpp>

using namespace Rosterer;

InitialRosterManager& InitialRosterManager::instance() {
    static InitialRosterManager instance;
    return instance;
}

InitialRosterManager::InitialRosterManager() {
}

void InitialRosterManager::readInitialSolution() {
    _initialSolution = Solution();
    _calendar = std::vector<std::vector<bool>>();

    _staff = readStaff();
    readCalendarAndInitialSolution(_initialSolution, _calendar);

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

const std::vector<std::string> InitialRosterManager::readStaff() const {
    std::vector<std::string> allStaff;
    io::CSVReader<2> in("../sample_staff.csv");
    in.read_header(io::ignore_extra_column, "name", "site");
    std::string name; std::string site;
    while (in.read_row(name, site)) {
        Staff staff = Staff(name, site);
        allStaff.push_back(staff.getName());
    }
    return allStaff;
}

void InitialRosterManager::readCalendarAndInitialSolution(Solution& solution, std::vector<std::vector<bool>>& calendar) {
    std::vector<int> nighttimeRoster; std::vector<int> daytimeRoster;
    io::CSVReader<7> in("../sample_roster.csv");
    in.read_header(io::ignore_extra_column, "day", "section", "assignee", "isWeekend", "isHolidaySite1", "isHolidaySite2", "isHolidaySite3");
    std::string day; std::string section; std::string assignee; int isWeekend; int isHolidaySite1; int isHolidaySite2; int isHolidaySite3;
    while (in.read_row(day, section, assignee, isWeekend, isHolidaySite1, isHolidaySite2, isHolidaySite3)) {
        calendar.push_back({isWeekend == 1, isHolidaySite1 == 1, isHolidaySite2 == 1, isHolidaySite3 == 1});
        auto staffIt = std::find_if(_staff.begin(), _staff.end(), [assignee](const std::string& l) {
            return l == assignee;
        });
        int staffIdx = std::distance(_staff.begin(), staffIt);
        if (section == "night") {
            nighttimeRoster.push_back(staffIdx);
        }
        else if (section == "day") {
            daytimeRoster.push_back(staffIdx);
        }
    }
    solution.setRosters(std::move(nighttimeRoster), std::move(daytimeRoster)); // TODO coredump somewhere
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