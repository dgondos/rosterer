#include <Objective.hpp>

#include <InitialRosterManager.hpp>
#include <StaffManager.hpp>

using namespace Rosterer;

long Objective::computeCost(const Solution& solution) {
    return minimizeSwapsDuringDay(solution) +
    minimizeConsecutiveWeeks(solution) +
    minimizeDayNightSwaps(solution) +
    minimizeSwapsDuringWeek(solution) +
    maximizeRest(solution) +
    maximizeFairness(solution) +
    minimizeDisruption(solution);
}

long Objective::minimizeSwapsDuringDay(const Solution& solution) {
    return 0; // TODO need to implement multiple shifts per day for this
}

long Objective::minimizeConsecutiveWeeks(const Solution& solution) {
    long cost = 0;
    for (int sundayIdx = InitialRosterManager::getFirstSundayIdx(); sundayIdx < InitialRosterManager::getNbrDaysOptimized(); sundayIdx += 7) {
        int mondayIdx = sundayIdx + 1;
        if (mondayIdx >= InitialRosterManager::getNbrDaysOptimized()) {
            break;
        }
        if (solution.getNighttimeRoster().at(sundayIdx) == solution.getNighttimeRoster().at(mondayIdx)) {
            cost += 500;
        }
    }
    return cost;
}

long Objective::minimizeDayNightSwaps(const Solution& solution) {
    long cost = 0;
    for (int idx = 0; idx < InitialRosterManager::getNbrDaysOptimized(); idx++) {
        if (solution.getDaytimeRoster().at(idx) != solution.getNighttimeRoster().at(idx)) {
            cost += 400;
        }
    }
    return cost;
}

long Objective::minimizeSwapsDuringWeek(const Solution& solution) {
    long cost = 0;
    for (int idx = 0; idx < InitialRosterManager::getNbrDaysOptimized(); idx++) {
        int nextDayIdx = idx + 1;
        if (nextDayIdx >= InitialRosterManager::getNbrDaysOptimized()) {
            break;
        }
        if (solution.getDaytimeRoster().at(idx) != solution.getDaytimeRoster().at(nextDayIdx)) {
            cost += 100;
        }
    }
    return cost;
}

long Objective::maximizeRest(const Solution& solution) {
    // rest is defined as weeks between two sunday assignments
    std::vector<int> minimumRestWeeksForStaff(StaffManager::getAllStaff().size(), 0);

    for (int sundayIdx = InitialRosterManager::getFirstSundayIdx(); sundayIdx < InitialRosterManager::getNbrDaysOptimized(); sundayIdx += 7) {
        int staffThisSunday = solution.getNighttimeRoster().at(sundayIdx);
        int restWeeksForStaff = 0;
        for (int nextSundayIdx = sundayIdx + 7; nextSundayIdx < InitialRosterManager::getNbrDaysOptimized(); nextSundayIdx += 7) {
            if (solution.getNighttimeRoster().at(nextSundayIdx) == staffThisSunday) {
                break;
            }
            else {
                restWeeksForStaff++;
            }
        }
        if (minimumRestWeeksForStaff.at(staffThisSunday) > restWeeksForStaff) {
            minimumRestWeeksForStaff[staffThisSunday] = restWeeksForStaff;
        }
    }

    int target = StaffManager::getAllStaff().size() - 1; // ideal case: fully sequential assignments

    long variance = 0;
    for (std::vector<int>::const_iterator it = minimumRestWeeksForStaff.begin(); it != minimumRestWeeksForStaff.end(); ++it) {
        variance += (*it - target) * (*it - target);
    }

    return variance * 0.5;
}

long Objective::maximizeFairness(const Solution& solution) {
    // fairness is defined as equality for assigned nighttime shifts for a staff

    std::vector<int> nbrAssignmentsForStaff(StaffManager::getAllStaff().size(), 0);

    for (int staffIdx = 0; staffIdx < StaffManager::getAllStaff().size(); staffIdx++) {
        int assignmentsForCurrentStaff = 0;
        for (int dayIdx = 0; dayIdx < InitialRosterManager::getNbrDaysOptimized(); dayIdx++) {
            if (solution.getNighttimeRoster().at(dayIdx) == staffIdx) {
                assignmentsForCurrentStaff++;
            }
        }
        nbrAssignmentsForStaff[staffIdx] = assignmentsForCurrentStaff;
    }

    double mean = InitialRosterManager::getNbrDaysOptimized() / StaffManager::getAllStaff().size();

    long variance = 0;
    for (std::vector<int>::const_iterator it = nbrAssignmentsForStaff.begin(); it != nbrAssignmentsForStaff.end(); ++it) {
        variance += (*it - mean) * (*it - mean);
    }

    return variance * 0.5;
}

long Objective::minimizeDisruption(const Solution& solution) {
    long cost = 0;
    for (int idx = 0; idx < InitialRosterManager::getNbrDaysOptimized(); idx++) {
        if (solution.getDaytimeRoster().at(idx) != InitialRosterManager::getInitialSolution().getDaytimeRoster().at(idx)) {
            cost += 1;
        }
        if (solution.getNighttimeRoster().at(idx) != InitialRosterManager::getInitialSolution().getNighttimeRoster().at(idx)) {
            cost += 1;
        }
    }
    return cost;
}
